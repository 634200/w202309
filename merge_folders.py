import os
import shutil
import filecmp


def merge_folders(destination_folder, source_folder):
    # 遍历源文件夹中的所有文件
    for root, dirs, files in os.walk(source_folder):
        for file in files:
            # 获取源文件的路径和目标文件的路径
            source_file_path = os.path.join(root, file)
            destination_file_path = os.path.join(destination_folder, file)
            # 如果目标文件不存在直接移动过去
            if not os.path.exists(destination_file_path):
                shutil.move(source_file_path, destination_folder)
                print(f"已将 {source_file_path} 移动到 {destination_folder} 中")
            # 目标与源文件内容相同，则跳过
            elif filecmp.cmp(source_file_path, destination_file_path):
                print(f"跳过 {source_file_path}，因为它已经存在于 {destination_folder} 中并且内容相同")
            else:
                # 目标与源文件内容不同，则移动过去（重命名）
                filename, extension = os.path.splitext(file)
                new_filename = f"{filename}_new{extension}"
                new_file_path = os.path.join(destination_folder, new_filename)
                shutil.move(source_file_path, new_file_path)
                print(f"已将 {source_file_path} 移动到 {new_file_path} 中")


# 示例用法
# merge_folders("path/to/destination/folder", "path/to/source/folder")
merge_folders("../payment-demo-front", "../vue-demo")
