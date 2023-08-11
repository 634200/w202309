package com.xftxyz.vcfparser;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.Collator;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.stream.Collectors;

import ezvcard.Ezvcard;
import ezvcard.VCard;
import ezvcard.property.FormattedName;

public class Main {

    // 排序a-z
    public static void sort(List<VCard> vCards) {
        System.out.println(vCards.size() + "个联系人待排序");
        Collator collator = Collator.getInstance(Locale.CHINESE);

        vCards.sort((a, b) -> {
            FormattedName fn1 = a.getFormattedName();
            FormattedName fn2 = b.getFormattedName();
            if (fn1 == null || fn2 == null) {
                return 0;
            }
            // System.out.println(fn1.getValue() + ":" + fn2.getValue());
            return collator.compare(fn1.getValue(), fn2.getValue());
        });
        System.out.println("排序完成");
    }

    // 读取vcf
    public static List<VCard> read(String pathStr) throws IOException {
        System.out.println("读取" + pathStr);
        Path path = Paths.get(pathStr);
        List<VCard> all = Ezvcard.parse(path).all();
        System.out.println("读取完成");
        System.out.println("共读取" + all.size() + "个联系人");
        return all;
    }

    // 按照FN写出到不同的文件
    public static void map(List<VCard> vCards) throws IOException {
        System.out.println("mapping...");
        for (VCard vCard : vCards) {
            String fn = vCard.getFormattedName().getValue();
            Path path = Paths.get("./tmp/" + fn + ".vcf");
            if (!path.toFile().exists()) {
                path.toFile().createNewFile();
            }
            Ezvcard.write(vCard).go(path, true);
        }
        System.out.println("mapped");
    }

    // 扫描tmp路径下的vcf文件
    public static List<Path> scan() throws IOException {
        System.out.println("正在扫描tmp下的文件...");
        // 得到tmp下的所有vcf文件
        Path tmpDir = Paths.get("tmp");
        List<Path> vcfFiles = Files.list(tmpDir)
                .filter(p -> p.toString().toLowerCase().endsWith(".vcf"))
                .collect(Collectors.toList());
        System.out.println("扫描完成，共扫描到" + vcfFiles.size() + "个文件");
        return vcfFiles;
    }

    // 合并不冲突的文件
    public static List<VCard> merge(List<Path> vcfFiles) throws IOException {
        // 重复计数
        long repeatCount = 0;
        // 合并所有的vcf文件
        List<VCard> mergeList = new ArrayList<>();
        for (Path path : vcfFiles) {
            System.out.println("正在合并" + path);
            List<VCard> vCard = Ezvcard.parse(path).all();
            if (vCard.size() != 1) {
                // 如果vcf文件包含不止一个vcard，跳过
                repeatCount++;
                continue;
            }
            VCard card = vCard.get(0);
            mergeList.add(card);
            // 删除文件
            path.toFile().delete();
        }
        System.out.println("合并完成，共合并" + mergeList.size() + "个联系人，跳过" + repeatCount + "个重复文件");
        return mergeList;
    }

    // 单纯合并
    public static void mergeOnly(List<Path> vcfFiles) throws IOException {
        Path filename = getOneFile();
        for (Path path : vcfFiles) {
            System.out.println("正在合并" + path);
            List<VCard> vCards = Ezvcard.parse(path).all();
            Ezvcard.write(vCards).go(filename, true);
            // 删除文件
            path.toFile().delete();
        }
        System.out.println("合并完成");
        // changeEncoding(filename);
    }

    // 写出vcf
    public static void write(List<VCard> vCards) throws IOException {
        System.out.println("写出" + vCards.size() + "个联系人");
        Path path = getOneFile();
        Ezvcard.write(vCards).go(path);
        System.out.println("写出完成");
    }

    // 创建一个文件
    public static Path getOneFile() throws IOException {
        String pathStr = "./" + System.currentTimeMillis() + ".vcf";
        Path path = Paths.get(pathStr);
        if (!path.toFile().exists()) {
            path.toFile().createNewFile();
        }
        return path;
    }

    // 编码转换
    public static void changeEncoding(Path path) throws IOException {
        // 读取文件
        File file = path.toFile();
        FileInputStream fis = new FileInputStream(file);
        InputStreamReader isr = new InputStreamReader(fis, "gb2312");

        // 写入文件
        File outputFile = new File(file.getParent(), "utf8_" + file.getName());

        FileOutputStream fos = new FileOutputStream(outputFile);
        OutputStreamWriter osw = new OutputStreamWriter(fos, "utf-8");

        // 逐行读取并写入
        BufferedReader br = new BufferedReader(isr);
        BufferedWriter bw = new BufferedWriter(osw);
        String line;
        while ((line = br.readLine()) != null) {
            bw.write(line);
            bw.newLine();
        }

        // 关闭流
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        // 合并tmp下的vcf文件
        // List<VCard> read = read("./1691660368133.vcf");
    }

}