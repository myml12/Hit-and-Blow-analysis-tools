#include <stdio.h>
int main(void) {

	printf("Hit and Blow (4��) ��̓c�[�� Ver1.0 �ւ悤����\n");

	char opt[10][10][10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {

					if (i != j && j != k && i != k && i != l && j != l && k != l) {
						//�e�ʂ̒l���S�ĈقȂ�5040�ʂ���i�[

						opt[i][j][k][l] = 't';
						//opt�̒l��t�Ȃ�Ή\���Ƃ��Ă��肦��
					}

					else {
						opt[i][j][k][l] = 'f';
						//opt�̒l��f�Ȃ�Ή\���Ƃ��Ă��肦�Ȃ�
					}
				}
			}
		}
	}

	int count = 0;

	do{
		char numc[5];

		if (count > 0) {
			printf("\n");
		}

		printf("\n��͂���l����͂��Ă��������F");
		scanf("%s", numc);
		//numc�z��ɉ�͒l���i�[

		if (numc[0] == 'e') {
			break;
		}

		int numcc[4] = { numc[0] - '0', numc[1] - '0',numc[2] - '0',numc[3] - '0' };
		//�����R�[�h�𐔎��R�[�h�ɕϊ�
		//��͂��鐔�l��numcc�z��[4]��int�^�Ŋi�[�����

		int hit, blow;

		printf("hit������͂��Ă��������F");
		scanf("%d", &hit);

		if (hit == 4) {
			printf("Win!\n");
			break;
		}

		printf("blow������͂��Ă��������F");
		scanf("%d", &blow);

		//����ƈ�v���Ȃ�Hit,Blow�������O���邽��

		int hitc = 0;
		int blowc = 0;
		//���[�v���Ŏg�p����J�E���g


		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					for (int l = 0; l < 10; l++) {

						if (opt[i][j][k][l] == 't') {

							//printf("%d %d %d %d", numcc[0], numcc[1], numcc[2], numcc[3]);
							//OK
							
							int num[4] = { i ,j ,k ,l };
							//num[4]�z��ɂ��ꂼ��\������l���i�[(�S�T�j
							//�v���C���[�h�ő��肪���߂Ă��鐔�̖�����num[4]�z�񂪂�������

							//printf("%d %d %d %d\n", num[0], num[1], num[2], num[3]);
							//OK

							hitc = 0;
							blowc = 0;
							//Hitc,Blowc�̃J�E���g�����[�v���Ƀ��Z�b�g

							for (int m = 0; m < 4; m++) {

								if (num[m] == numcc[m]) {
									hitc++;
								}
								//�ʂ̐�������v�����hitc��+1

								else {

									for (int n = 0; n < 4; n++) {

										if (m != n) {
											if (num[m] == numcc[n]) {
												blowc++;
											}
											//�ʂ̐�������v�����A���̈ʂƐ�������v������blowc��+1
										}
									}
								}

							}//hitc,blowc�����J�E���g

							//printf("%d %d\n", hitc, blowc);


							if (hit == hitc && blow == blowc) {
								continue;
							}
							//��v�����珑���������Ɍ��݂̃��[�v���X�L�b�v

							opt[i][j][k][l] = 'f';
							//Hit,Blow��������ɂȂ�Ȃ����opt[i][j][k][l]��'f'����

						}
					}
				}
			}
		}

		printf("\n�ȉ����l����ꂤ�鐔�ł�\n\n");

		int count20 = 0;
		//�o�͂̉��s�p�J�E���g

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					for (int l = 0; l < 10; l++) {

						if (opt[i][j][k][l] == 't') {

							int output = i * 1000 + j * 100 + k * 10 + l;
							printf("%04d ", output);
							//opt�̒l��'t'�ł�����̂�S�ďo��

							count20++;

							if (count20 == 20) {
								printf("\n");
								count20 = 0;
							}
						}
					}
				}
			}
		}

		count++;

	}while (count < 100);
	//��͉񐔂�100��ɒB������v���O�������I������

	system("pause");
	
	return 0;
}