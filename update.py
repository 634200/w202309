# 未成功

import subprocess

# 获取已过期的包列表
output = subprocess.check_output(["pip", "list", "--outdated"])
packages = output.decode("utf-8").strip().split("\n")[2:]

# 检查每个包是否过期并更新
for package in packages:
    package_name, current_version, latest_version = package.split()
    print(f"检查 {package_name} 的过期情况...")
    if current_version != latest_version:
        print(f"{package_name} 已过期，当前版本：{current_version}，最新版本：{latest_version}")
        print(f"正在更新 {package_name}...")
        subprocess.call(["pip", "install", "--upgrade", package_name])
    else:
        print(f"{package_name} 当前已是最新版本：{current_version}")
