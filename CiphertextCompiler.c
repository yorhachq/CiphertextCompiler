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

	return ascii;                    // ascii ����֮ǰδ�ͷ�
}

int main(void)
{
	static char original[1024 * 1024], str1[1024 * 1024], str2[1024 * 1024], jam[1024 * 1024], ch[2];
	memset(original, 0, sizeof(original));//�淶��ʼ�����飬����warning C4047
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	memset(jam, 0, sizeof(jam));
	memset(ch, 0, sizeof(ch));

	char* org = original, * fir = str1, * sec = str2, * pjam = jam, * chs = NULL;
	int check = 0, distance = 0, i = 0, j = 0, parameter = 0, move = 0, len = 0, LEN = 0, get = 0;
	double temp = 0.0;
	
//	system("mode con cols=110 lines=30");//�����ô��ڴ�С����������ݹ���ʱ�����޷�������ʾ���������޷����¹�����
	system("color 0B");//0=��ɫ1=��ɫ2=��ɫ3=����ɫ4=��ɫ5=��ɫ6=��ɫ7=��ɫ8=��ɫ9=����ɫA=����ɫB=��ǳ��ɫC=����ɫD=����ɫE=����ɫF=����ɫ
	printf("\n\n\n\n\n\n\n\n\n                               ��  ӭ  ʹ  ��  C H Q  ��  ��  ��  ��  ��  ��  ��\n");
	printf("\n\n\n\n\n\n\n                                        1.�� ��                2.�� ��\n\n\n\n");

	do
	{
		switch (getch())
		{
		case '1':check = 1; break;
		case '2':check = 2; break;
		default:check = 0;
		}
	} while (check == 0);

	if (check == 1)////////////////////////////////////////////////////////////////////////////////////////////���ܲ���
	{
		check = 0;
		system("cls");
		printf("����������ܵ��ַ���:\n");
		do
		{
			if (check == 2)
			{
				get = getchar();//��ջ�����
				org = original;//��ԭָ��ָ��
			}
			gets_s(original, 512 * 512);//gets�� ISO/IEC 9899 2011(C11)��׼���ѱ��Ƴ�,����VS��ʹ�û����warning��gets_s�Ĳ���Ϊ�洢�ַ����Ŀռ䳤��
			while (*org)
			{
				if (*org >= 32 && *org <= 126)//ȷ���û��������Ҫ����ַ���
				{
					check = 1;
					org++;
				}
				else
				{
					printf("\n�ݲ�֧�����ģ�����������:\n");
					printf("%c", 7);
					check = 2;
					break;
				}
			}
		} while (check != 1);
		org = original;//��ԭָ��λ��
		check = 0;
		LEN = strlen(org);

		printf("\n�����ܵ��ַ�������Ϊ%d,�Ƿ�ȷ�ϼ���(Y/N)\n", LEN);
		do //���û����쳣��Ϊ����Ӧ��
		{
			switch (getch())
			{
			case 'Y':
			case 'y':check = 1; break;
			case 'N':
			case 'n':printf("\n����ȡ������\n"); get = getchar(); exit(0);
			default:system("cls"); printf("��Ч����,��ѡ���Ƿ����(Y/N)\n");
			}
		} while (check == 0);
		check = 0;

		system("cls");
		printf("����������:\n");//����==������Ϣ
		do
		{
			if (check == 2)
			{
				get = getchar();//��ջ�����
				pjam = jam;//��ԭָ��ָ��
			}
			gets_s(jam, 512 * 512);
			while (*pjam)//ȷ���û��������Ҫ��ĸ�����Ϣ
			{
				if (*pjam >= 32 && *pjam <= 126)
				{
					check = 1;
					pjam++;
				}
				else
				{
					printf("\n�ݲ�֧�����ģ�����������:\n");
					printf("%c", 7);
					check = 2;
					break;
				}

			}

		} while (check != 1);
		pjam = jam;//��ԭָ��λ��
		check = 0;

		system("cls");
		printf("������һ����Կ����������:\n");//��Կһ==������
		do
		{
			if (check == 2)
			{
				do//��ջ�����
				{
					get = getchar();
				} while (get != '\n');

			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//���������,ȷ���������ݺϷ�
			{
				system("cls");
				printf("һ����ԿӦΪ������������������:\n");
				check = 2;
			}
			else
			{
				if ((int)temp >= LEN)
				{
					system("cls");
					printf("һ����ԿӦС�ڴ���%d������������:\n", LEN);
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
			if (*pjam)//������Ϣδȫ������ʱ�����������Ϣ
			{
				*fir = *pjam;
				fir++;
				pjam++;

			}
			for (i = 0; i < distance; i++)//��ԭ������д���´�
			{
				*fir = *org;
				fir++;
				org++;
			}
		}
		fir = str1;//��ԭָ��λ��
		len = strlen(str1);

		system("cls");
		printf("�����������Կ(������):\n");//������Կ==��׼��
		do
		{
			if (check == 2)
			{
				do//��ջ�����
				{
					get = getchar();
				} while (get != '\n');
			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//�����׼����ȷ���������ݺϷ�
			{
				system("cls");
				printf("������Կ��Ϊ������������������:\n");
				check = 2;
			}
			else
			{
				if ((int)temp >= len)
				{
					system("cls");
					printf("������Կ��С�ڴ���%d������������:\n", len);
					check = 2;
				}
				else
					check = 1;
			}
		} while (check != 1);
		check = 0;
		parameter = (int)temp;//������ͨ���Ļ�׼����Ϊ���������ͨ���㷨�ó�����λ����

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
		fir = str1;//��ԭָ��λ��
		sec = str2;

		system("cls");
		printf("������ɣ����¼��Կ������\n\nһ����Կ:%d\n\n������Կ:%d\n\n������Կ:%d\n\n����:", distance, parameter, len);
		puts(jam);
		printf("\n���ܺ���ַ���Ϊ:\n");
		printf("%s\n", chstohex(sec));
	}
	else///////////////////////////////////////////////////////////////////////////////////////////////////////���ܲ���
	{
		check = 0;
		system("cls");
		printf("����������ܵ��ַ���:\n");
		do
		{
			if (check == 2)
			{
				get = getchar();//��ջ�����
				org = original;//��ԭָ��ָ��
			}
			gets_s(original, 512 * 512);//gets�� ISO/IEC 9899 2011(C11)��׼���ѱ��Ƴ�,����VS��ʹ�û����warning��gets_s�Ĳ���Ϊ�洢�ַ����Ŀռ䳤��
			while (*org)//ȷ���û��������Ҫ����ַ���
			{
				if (*org >= 32 && *org <= 126)
				{
					check = 1;
					org++;
				}
				else
				{
					printf("\n�����ܴ���������������:\n");
					printf("%c", 7);
					check = 2;
					break;
				}
			}
		} while (check != 1);
		org = original;//��ԭָ��λ��
		check = 0;
		LEN = strlen(org);

		//��������(hextochs)
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

		//��������(move)
		system("cls");
		printf("������������Կ:\n");//������Կ==һ�����ܺ�Ĵ���
		do
		{
			if (check == 2)
			{
				do//��ջ�����
				{
					get = getchar();
				} while (get != '\n');
				printf("������������Կ:\n");
			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//���봮����ȷ���������ݺϷ�
			{
				system("cls");
				printf("�Ƿ����룡\n");
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
		printf("�����������Կ:\n");//������Կ==��׼��
		do
		{
			if (check == 2)
			{
				do//��ջ�����
				{
					get = getchar();
				} while (get != '\n');
				printf("�����������Կ:\n");
			}
			if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//�����׼����ȷ���������ݺϷ�
			{
				system("cls");
				printf("�Ƿ����룡\n");
				check = 2;
			}
			else
			{
				if ((int)temp >= LEN)
				{
					system("cls");
					printf("�Ƿ����룡\n");
					check = 2;
				}
				else
					check = 1;
			}
		} while (check != 1);
		parameter = (int)temp;//������ͨ���Ļ�׼����Ϊ���������ͨ���㷨�ó�����λ����
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
		sec = str2;//��ԭָ��λ��

		//һ������(delete)
		system("cls");
		printf("������һ����Կ:\n");//һ����Կ==������
		do
		{
			    if (check == 2) 
			    {
				    do
				    {
					    get = getchar();
				    } while (get != '\n');
					printf("������һ����Կ:\n");
			    }  
			    if (!scanf_s("%lf", &temp) || temp <= 0 || (int)temp != temp)//���������,ȷ���������ݺϷ�
				{
				    system("cls");
					printf("�Ƿ����룡\n");
					check = 2;
				}
				else
				{
					if ((int)temp >= LEN)
					{
						system("cls");
						printf("�Ƿ����룡\n");
						check = 2;
					}
					else
						check = 1;
				}

		} while (check != 1);
		check = 0;
		distance = (int)temp;

		system("cls");
		printf("����������:\n");//����==������Ϣ
		do
		{
			if (check == 2)
			{
				get = getchar();//��ջ�����
				pjam = jam;
			}
			gets_s(jam, 512 * 512);
			while (*pjam)//ȷ���û��������Ҫ��ĸ�����Ϣ
			{
				if (*pjam >= 32 && *pjam <= 126)
				{
					check = 1;
					pjam++;
				}
				else
				{
					system("cls");
					printf("�Ƿ����룬����������:\n");
					printf("%c", 7);
					check = 2;
					break;
				}

			}

		} while (check != 1);
		pjam = jam;//��ԭָ��λ��
		check = 0;

		sec++;//���ݼ����㷨��Ӧ����ԭ����λ
		while (*sec)
		{
			if (*pjam)
			{
				for (i = 0; i < distance; i++)//�Ը�����Ϣ����λ�ý��б��
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
		fir = str1;//��ԭָ��λ��
		sec = str2;

		system("cls");
		printf("���ܺ���ַ���Ϊ:\n");
		puts(fir);
	}

//	printf("\n��л����ʹ�ã������߼���ˮƽ���ޣ�������ڲ���֮������ӭ����ָ��\nQQ:3427443198\n");
	printf("\n��Ҫ�رմ��ڣ��밴�»س���");

	get = getchar();
	get = getchar();

	return 0;
}