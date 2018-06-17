from bs4 import BeautifulSoup
import requests
import re

def getHtml(url):
    hders = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 '
                      '(KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36',
    }
    try:
        r = requests.get(url, headers=hders, timeout=10)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return -1

def bsHmtl(htmlText):
    soup = BeautifulSoup(htmlText, 'lxml')
    infoBox = soup.find_all('tr', class_='item')
    for song in infoBox:
        print(song.find('div', class_='pl2').find('a').getText(), end=' ')
        print(song.find('p', class_='pl').getText(), end='\n')
        print(song.find('span', class_='pl').getText().strip().strip('()').strip(), end='     ')
        print(song.find('span', class_='rating_nums').getText(), end='\n')


def main():
    url = 'http://music.douban.com/top250'
    html = getHtml(url)
    bsHmtl(html)

main()