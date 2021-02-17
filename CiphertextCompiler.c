#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

char* chstohex(char* chs)
{
	char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int len = strlen(chs);
	char* ascii = NULL;
	ascii = (char*)calloc(len * 3 + 1, sizeof(char));            // calloc ascii

	int i = 0;
	while (i < len)
	{
		if (ascii)
		{
			ascii[i * 2] = hex[(int)((char)chs[i] / 16)];
			ascii[i * 2 + 1] = hex[(int)((char)chs[i] % 16)];
			++i;
		}

	}

	return ascii;                    // ascii 返回之前未释放
}

int main(void)
{
	static char original[1024 * 1024], str1[1024 * 1024], str2[1024 * 1024], jam[1024 * 1024], ch[2];
	memset(original, 0, sizeof(original));//规范初始化数组，消除warning C4047
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	memset(jam, 0, sizeof(jam));
	memset(ch, 0, sizeof(ch));

	char* org = original, * fir = str1, * sec = str2, * pjam = jam, * chs = NULL;
	int check = 0, distance = 0, i = 0, j = 0, parameter = 0, move = 0, len = 0, LEN = 0, get = 0;
	double temp = 0.0;
	
//	system("mode con cols=110 lines=30");//若设置窗口大小，当输出内容过长时，将无法完整显示（窗口内无法上下滚动）
	system("color 0B");//0=黑色1=蓝色2=绿色3=湖蓝色4=红色5=紫色6=黄色7=白色8=灰色9=淡蓝色A=淡绿色B=淡浅绿色C=淡红色D=淡紫色E=淡黄色F=亮白色
	printf("\n\n\n\n\n\n\n\n\n                               欢  迎  使  用  C H Q  文  本  加  解  密  工  具\n");
	printf("\n\n\n\n\n\n\n                                        1.加 密                2.解 密\n\n\n\n");

	do
	{
		switch (getch())
		{
		case '1':check = 1; break;
		case '2':check = 2; break;
		default:check = 0;
		}
	} while (check == 0);

	if (check == 1)////////////////////////////////////////////////////////////////////////////////////////////加密部分
	{
		check = 0;
		system("cls");
		printf("请输入需加密的字符串:\n");
		do
		{
			if (check == 2)
			{
				get = getchar();//清空缓冲区
				org = original;//还原指针指向
			}
			gets_s(original, 512 * 512);//gets在 ISO/IEC 9899 2011(C11)标准中已被移除,若在VS中使用会产生warning，gets_s的参数为存储字符串的空间长度
			while (*org)
			{
				if (*org >= 32 && *org <= 126)//确保用户输入符合要求的字符串
				{
					check = 1;
					org++;
				}
				else
				{
					printf("\n暂不支持中文，请重新输入:\n");
					printf("%c", 7);
					check = 2;
					break;
				}
			}
		} while (check != 1);
		org = original;//还原指针位置
		check = 0;
		LEN = strlen(org);

		printf("\n待加密的字符串串长为%d,是否确认加密(Y/N)\n", LEN);
		do //对用户的异常行为进行应对
		{
			switch (getch())
			{
			case 'Y':
			case 'y':check = 1; break;
			case 'N':
			case 'n':printf("\n您已取消加密\n"); get = getchar(); exit(0);
			default:system("cls"); printf("无效输入,请选择是否加密(Y/N)\n");
			}
		} while (check == 0);
		check = 0;

		system("cls");
		printf("请输入密码:\n");//密码==干扰信息
		do
		{
			if (check == 2)
			{
				get = getchar();//清空缓冲区
				pjam = jam;//还原指针指向
			}
			gets_s(jam, 512 * 512);
			while (*pjam)//确保用户输入符合要求的干扰信息
			{
				if (*pjam >= 32 && *pjam <= 126)
				{
					check = 1;
					pjam++;
				}
				else
				{
					printf("\n暂不支持中文，请重新输入:\n");
					printf("%c", 7);
					check = 2;
					break;
				}

			}

		} while (check != 1);
		pjam = jam;//还原指针位置
		check = 0;

		system("cls");
		printf("请输入一级密钥（正整数）:\n");//密钥一==插入间距
		do
		{
			if (check == 2)
			{
				do//清空缓冲区
				{
					get = getchar();
				} while (get != '\n');

			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//输入插入间距,确保输入内容合法
			{
				system("cls");
				printf("一级密钥应为正整数，请重新输入:\n");
				check = 2;
			}
			else
			{
				if ((int)temp >= LEN)
				{
					system("cls");
					printf("一级密钥应小于串长%d，请重新输入:\n", LEN);
					check = 2;
				}
				else
					check = 1;
			}

		} while (check != 1);
		check = 0;
		distance = (int)temp;

		while (*org)
		{
			if (*pjam)//干扰信息未全部插入时，插入干扰信息
			{
				*fir = *pjam;
				fir++;
				pjam++;

			}
			for (i = 0; i < distance; i++)//将原串内容写入新串
			{
				*fir = *org;
				fir++;
				org++;
			}
		}
		fir = str1;//还原指针位置
		len = strlen(str1);

		system("cls");
		printf("请输入二级密钥(正整数):\n");//二级密钥==基准量
		do
		{
			if (check == 2)
			{
				do//清空缓冲区
				{
					get = getchar();
				} while (get != '\n');
			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//输入基准量，确保输入内容合法
			{
				system("cls");
				printf("二级密钥需为正整数，请重新输入:\n");
				check = 2;
			}
			else
			{
				if ((int)temp >= len)
				{
					system("cls");
					printf("二级密钥需小于串长%d，请重新输入:\n", len);
					check = 2;
				}
				else
					check = 1;
			}
		} while (check != 1);
		check = 0;
		parameter = (int)temp;//将检验通过的基准量作为计算参数，通过算法得出最终位移量

		if (parameter < 3)
			move = (len / parameter) - (len / 3);
		else if ((len - parameter) > 94)
			move = (len - parameter) / 2;
		else
			move = (len / parameter) + (len / 4);
		while (move > 94)
		{
			move /= 2;
		}

		while (*fir)
		{
			if (*fir + move > 126)
			{
				*sec = *fir + move - 95;
			}
			else
			{
				*sec = *fir + move;
			}
			fir++;
			sec++;
		}
		fir = str1;//还原指针位置
		sec = str2;

		system("cls");
		printf("加密完成！请记录密钥及密码\n\n一级密钥:%d\n\n二级密钥:%d\n\n三级密钥:%d\n\n密码:", distance, parameter, len);
		puts(jam);
		printf("\n加密后的字符串为:\n");
		printf("%s\n", chstohex(sec));
	}
	else///////////////////////////////////////////////////////////////////////////////////////////////////////解密部分
	{
		check = 0;
		system("cls");
		printf("请输入需解密的字符串:\n");
		do
		{
			if (check == 2)
			{
				get = getchar();//清空缓冲区
				org = original;//还原指针指向
			}
			gets_s(original, 512 * 512);//gets在 ISO/IEC 9899 2011(C11)标准中已被移除,若在VS中使用会产生warning，gets_s的参数为存储字符串的空间长度
			while (*org)//确保用户输入符合要求的字符串
			{
				if (*org >= 32 && *org <= 126)
				{
					check = 1;
					org++;
				}
				else
				{
					printf("\n待解密串有误，请重新输入:\n");
					printf("%c", 7);
					check = 2;
					break;
				}
			}
		} while (check != 1);
		org = original;//还原指针位置
		check = 0;
		LEN = strlen(org);

		//三级解密(hextochs)
		if (LEN % 2 != 0)
			NULL;
		chs = (char*)calloc(LEN / 2 + 1, sizeof(char));                // calloc chs

		while (j < LEN)
		{
			if (chs)
			{
				ch[0] = ((int)org[j] > 64) ? (org[j] % 16 + 9) : org[j] % 16;
				ch[1] = ((int)org[j + 1] > 64) ? (org[j + 1] % 16 + 9) : org[j + 1] % 16;

				chs[j / 2] = (char)(ch[0] * 16 + ch[1]);
				j += 2;
			}
		}

		//二级解密(move)
		system("cls");
		printf("请输入三级密钥:\n");//三级密钥==一级加密后的串长
		do
		{
			if (check == 2)
			{
				do//清空缓冲区
				{
					get = getchar();
				} while (get != '\n');
				printf("请输入三级密钥:\n");
			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//输入串长，确保输入内容合法
			{
				system("cls");
				printf("非法输入！\n");
				check = 2;
			}
			else
			{
				LEN = (int)temp;
				check = 1;
			}
		} while (check != 1);
		check = 0;
		temp = 0;

		system("cls");
		printf("请输入二级密钥:\n");//二级密钥==基准量
		do
		{
			if (check == 2)
			{
				do//清空缓冲区
				{
					get = getchar();
				} while (get != '\n');
				printf("请输入二级密钥:\n");
			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//输入基准量，确保输入内容合法
			{
				system("cls");
				printf("非法输入！\n");
				check = 2;
			}
			else
			{
				if ((int)temp >= LEN)
				{
					system("cls");
					printf("非法输入！\n");
					check = 2;
				}
				else
					check = 1;
			}
		} while (check != 1);
		parameter = (int)temp;//将检验通过的基准量作为计算参数，通过算法得出最终位移量
		check = 0;
		temp = 0;

		if (parameter < 3)
			move = (LEN / parameter) - (LEN / 3);
		else if ((LEN - parameter) > 94)
			move = (LEN - parameter) / 2;
		else
			move = (LEN / parameter) + (LEN / 4);
		while (move > 94)
		{
			move /= 2;
		}

		while (*chs)
		{
			if (*chs - move < 32)
			{
				*sec = *chs - move + 95;
			}
			else
			{
				*sec = *chs - move;
			}
			chs++;
			sec++;
		}
		sec = str2;//还原指针位置

		//一级解密(delete)
		system("cls");
		printf("请输入一级密钥:\n");//一级密钥==插入间距
		do
		{
			    if (check == 2) 
			    {
				    do
				    {
					    get = getchar();
				    } while (get != '\n');
					printf("请输入一级密钥:\n");
			    }  
			    if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//输入插入间距,确保输入内容合法
				{
				    system("cls");
					printf("非法输入！\n");
					check = 2;
				}
				else
				{
					if ((int)temp >= LEN)
					{
						system("cls");
						printf("非法输入！\n");
						check = 2;
					}
					else
						check = 1;
				}

		} while (check != 1);
		check = 0;
		distance = (int)temp;

		system("cls");
		printf("请输入密码:\n");//密码==干扰信息
		do
		{
			if (check == 2)
			{
				get = getchar();//清空缓冲区
				pjam = jam;
			}
			gets_s(jam, 512 * 512);
			while (*pjam)//确保用户输入符合要求的干扰信息
			{
				if (*pjam >= 32 && *pjam <= 126)
				{
					check = 1;
					pjam++;
				}
				else
				{
					system("cls");
					printf("非法密码，请重新输入:\n");
					printf("%c", 7);
					check = 2;
					break;
				}

			}

		} while (check != 1);
		pjam = jam;//还原指针位置
		check = 0;

		sec++;//根据加密算法，应跳过原串首位
		while (*sec)
		{
			if (*pjam)
			{
				for (i = 0; i < distance; i++)//对干扰信息串的位置进行标记
				{
					*fir = *sec;
					fir++;
					sec++;
				}
				sec++;
				pjam++;
			}
			else
			{
				for (i = 0; i < distance; i++)
				{
					*fir = *sec;
					fir++;
					sec++;
				}
			}
		}
		fir = str1;//还原指针位置
		sec = str2;

		system("cls");
		printf("解密后的字符串为:\n");
		puts(fir);
	}

//	printf("\n感谢您的使用，因作者技术水平有限，难免存在不足之处，欢迎批评指正\nQQ:3427443198\n");
	printf("\n若要关闭窗口，请按下回车键");

	get = getchar();
	get = getchar();

	return 0;
}