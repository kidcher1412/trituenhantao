from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import getpass
from time import sleep
from selenium.webdriver.common.keys import Keys
print('----------packet the data---------------')
#tk=getpass.getpass(print('nhap tai khoan '))
#mk=getpass.getpass(print('nhap mat khau '))
tk="hoangthong1412@gmail.com"
mk="thongloveuyen"
driver= webdriver.Chrome()
driver.get('https://vi-vn.facebook.com')
driver.find_element_by_id('email').send_keys(tk)
driver.find_element_by_id('pass').send_keys(mk)
driver.find_element_by_xpath('/html/body/div[1]/div[2]/div[1]/div/div/div/div[2]/div/div[1]/form/div[2]/button').click()
sleep(10)
print('Finish log up!!!')
#check list data accout facebook by:
    #credential = open('tenfile.txt')
    #line = credential.readline()
    #tk=line[0]
    #mk=line[1]
driver.execute_script('document.querySelector("label.lzcic4wl.gs1a9yip.br7hx15l.h2jyy9rg.n3ddgdk9.owxd89k7.rq0escxv.j83agx80.a5nuqjux.l9j0dhe7.k4urcfbm.kbf60n1y.b3i9ofy5").click()')
driver.execute_script('document.querySelector("label.lzcic4wl.gs1a9yip.br7hx15l.h2jyy9rg.n3ddgdk9.owxd89k7.rq0escxv.j83agx80.a5nuqjux.l9j0dhe7.k4urcfbm.kbf60n1y.b3i9ofy5").click()')
driver.find_element_by_xpath('/html/body/div[1]/div/div[1]/div/div[2]/div[2]/div/div/div[1]/div/div/label/input').send_keys('clone')
driver.find_element_by_xpath('/html/body/div[1]/div/div[1]/div/div[2]/div[2]/div/div/div[1]/div/div/label/input').send_keys(Keys.ENTER)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

print('finish check OK~~')