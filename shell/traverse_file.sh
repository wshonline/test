#! /bin/bash
for file in ./*
do
    if test -f $file
    then
        echo $file 是文件
    fi
    if test -d $file
    then
        echo $file 是目录
        # 删除目录下的MP3文件夹
        cd $file
        rm -rf MP3
        cd ..
    fi
done