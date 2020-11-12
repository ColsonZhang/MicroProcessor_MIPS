import numpy as np 

def bin2hex(bin):
    term = 0
    for i in bin:
        term = term<<1
        if i =="1":
            term = term + 1
    return term


if __name__ == '__main__':

    code_bin = []
    code_dec = []
    code_hex = []
    write_content = ""
    with open("machine_bin.txt", "r") as f:  # 打开文件
        for line in f.readlines():
            line = line.strip('\n')  #去掉列表中每一个元素的换行符
            code_bin.append(line)
    
    for i in code_bin:
        term = bin2hex(i)
        code_dec.append(term)
        code_hex.append("{:#010X}".format(term))

    for i in code_hex:
        write_content += i + "\n"

    with open("machine_hex.txt","w+") as f:
        f.write(write_content)   


    