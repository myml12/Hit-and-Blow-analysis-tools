#include <stdio.h>
int main(void) {

	printf("Hit and Blow (3��) ��̓c�[�� Ver2.0 �ւ悤����\n");

	char opt[10][10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {

					if (i != j && j != k && i != k ) {
						//�e�ʂ̒l���S�ĈقȂ�720�ʂ���i�[

						opt[i][j][k]= 't';
						//opt�̒l��t�Ȃ�Ή\���Ƃ��Ă��肦��
					}

					else {
						opt[i][j][k]= 'f';
						//opt�̒l��f�Ȃ�Ή\���Ƃ��Ă��肦�Ȃ�
					}
			}
		}
	}

	int count = 0;

	do {
		char numc[4];

		if (count > 0) {
			printf("\n");
		}

		printf("\n��͂���l����͂��Ă��������F");
		scanf("%s", numc);
		//numc�z��ɉ�͒l���i�[

		if (numc[0] == 'e') {
			break;
		}

		int numcc[3] = { numc[0] - '0', numc[1] - '0',numc[2] - '0'};
		//�����R�[�h�𐔎��R�[�h�ɕϊ�
		//��͂��鐔�l��numcc�z��[3]��int�^�Ŋi�[�����

		int hit, blow;

		printf("hit������͂��Ă��������F");
		scanf("%d", &hit);

		if (hit == 3) {
			printf("Win!\n");
			break;
		}

		printf("blow������͂��Ă��������F");
		scanf("%d", &blow);

		//����ƈ�v���Ȃ�Hit,Blow�������O���邽��

		int hitc = 0;
		int blowc = 0;
		//���[�v���Ŏg�p����J�E���g


		//long cpu_time;
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {

						if (opt[i][j][k] == 't') {

							//printf("%d %d %d %d", numcc[0], numcc[1], numcc[2]);
							//OK

							int num[3] = { i ,j ,k };
							//num[3]�z��ɂ��ꂼ��\������l���i�[(�S�T�j
							//�v���C���[�h�ő��肪���߂Ă��鐔�̖�����num[4]�z�񂪂�������

							//printf("%d %d %d %d\n", num[0], num[1], num[2]);
							//OK

							hitc = 0;
							blowc = 0;
							//Hitc,Blowc�̃J�E���g�����[�v���Ƀ��Z�b�g

							for (int m = 0; m < 3; m++) {

								if (num[m] == numcc[m]) {
									hitc++;
								}
								//�ʂ̐�������v�����hitc��+1

								else {

									for (int n = 0; n < 3; n++) {

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

							opt[i][j][k] = 'f';
							//Hit,Blow��������ɂȂ�Ȃ����opt[i][j][k]��'f'����

						}
				}
			}
		}

		printf("\n�ȉ����l����ꂤ�鐔�ł�\n\n");

		int count30 = 0;
		//�o�͂̉��s�p�J�E���g

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {

						if (opt[i][j][k] == 't') {

							int output = i * 100 + j * 10 + k  ;
							printf("%03d ", output);
							//opt�̒l��'t'�ł�����̂�S�ďo��

							count30++;

							if (count30 == 30) {
								printf("\n");
								count30 = 0;
							}
						}
				}
			}
		}

		//cpu_time = clock();

		//printf("CPU���ԁF %d\n", cpu_time);

		count++;

	} while (count < 100);
	//��͉񐔂�100��ɒB������v���O�������I������

	system("pause");

	return 0;
}