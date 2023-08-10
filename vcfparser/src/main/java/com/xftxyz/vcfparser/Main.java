package com.xftxyz.vcfparser;

import java.io.IOException;
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
    }

    // 读取vcf
    public static List<VCard> read(String pathStr) throws IOException {
        Path path = Paths.get(pathStr);
        return Ezvcard.parse(path).all();
    }

    // 按照FN写出到不同的文件
    public static void map(List<VCard> vCards) throws IOException {
        for (VCard vCard : vCards) {
            String fn = vCard.getFormattedName().getValue();
            Path path = Paths.get("./tmp/" + fn + ".vcf");
            if (!path.toFile().exists()) {
                path.toFile().createNewFile();
            }
            Ezvcard.write(vCard).go(path, true);
        }
    }

    // 合并不冲突的文件
    public static List<VCard> merge() throws IOException {
        // 得到tmp下的所有vcf文件
        Path tmpDir = Paths.get("tmp");
        List<Path> vcfFiles = Files.list(tmpDir)
                .filter(p -> p.toString().toLowerCase().endsWith(".vcf"))
                .collect(Collectors.toList());

        // 合并所有的vcf文件
        List<VCard> mergeList = new ArrayList<>();

        for (Path path : vcfFiles) {
            List<VCard> vCard = Ezvcard.parse(path).all();
            if (vCard.size() != 1) {
                // 如果vcf文件包含不止一个vcard，跳过
                continue;
            }
            VCard card = vCard.get(0);
            mergeList.add(card);
            // 删除文件
            path.toFile().delete();
        }
        return mergeList;
    }

    // 写出vcf
    public static void write(List<VCard> vCards) throws IOException {
        Path path = Paths.get("./" + System.currentTimeMillis() + ".vcf");
        if (!path.toFile().exists()) {
            path.toFile().createNewFile();
        }
        Ezvcard.write(vCards).go(path);
    }

    // 合并并排序
    public static void mergeAndSort() throws IOException {
        List<VCard> vCards = merge();
        sort(vCards);
        write(vCards);
    }

    public static void main(String[] args) throws IOException {

        Path read = Paths.get("./ready.vcf");
        Path write = Paths.get("./out.vcf");
        write.toFile().createNewFile();

        List<VCard> all = Ezvcard.parse(read).all();
        sort(all);
        Ezvcard.write(all).go(write);

    }

}