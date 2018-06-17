import requests
import re
import time


def getHtml(url):

    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 '
                      '(KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'
    }

    try:
        r = requests.get(url, headers=header, timeout=10)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "获取网页失败！"


def bsHtml(html):
    partInfo = re.findall(r'\"poiLists\".*?\"comHeader\"', html)

    return partInfo


def printfInfo(infoList):
    path = 'E:/其他美食.txt'

    strInfoList = str(infoList)

    imgList = re.findall(r'\"frontImg\"\:\".*?\"', strInfoList)
    titleList = re.findall(r'\"title\"\:\".*?\"', strInfoList)
    scoreList = re.findall(r'\"avgScore\"\:.*?\,"', strInfoList)
    addressList = re.findall(r'\"address\"\:\".*?\"', strInfoList)
    priceList = re.findall(r'\"avgPrice\"\:[\d]*', strInfoList)
    with open(path, 'a') as file:
        try:
            for i in range(imgList.__len__()):
                file.write(titleList[i])
                file.write(scoreList[i].strip(','))
                file.write(priceList[i])
                file.write(addressList[i])
                file.write(imgList[i])
                file.write('\n')
        except:
            print("写入失败！")


def main():
    # startUrl = "http://hrb.meituan.com/meishi/c24/sales/"
    startUrl = "http://hrb.meituan.com/meishi/c24/"
    # for i in range(1, 14):
    #     html = getHtml(startUrl + "pn" + str(i) + "/")
    #     infoList = bsHtml(html)
    #     printfInfo(infoList)
    #     time.sleep(6)

    html = getHtml(startUrl)
    infoList = bsHtml(html)

    strInfoList = str(infoList)

    imgList = re.findall(r'\"title\"\:\".*?\"', strInfoList)
    print(imgList[0])
    printfInfo(infoList)


main()
