#include <stdio.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>
#include <openssl/bn.h>
#include <openssl/ec.h>
#include <openssl/sha.h>
char A[0x100], B[0x100], PE[0x100];   // ecc���߲���a, b, p
char GX[0x100], GY[0x100], NE[0x100]; // ����G��x����, y����, G�Ľ�(��Ϊ256λ)
char DE[0x100];                       // ecc��˽Կd(256λ)
char N1[2][0x100], D1[2][0x100], X2[2][0x100]; 
                // N1�����ecc��Կ���ܹ���rsa����N, 
                // ����N1[0]��ŵ�1��������, N1[1]��ŵ�2��������;
                // D1�����ecc��Կ���ܹ���rsa˽Կd;
                // X2�����ecc��Կ���ܹ���X1
char X1[0x100]; // X1�����rsa��Կ���ܹ���X                      
char X[0x100];  // X���һ��256λ�������, X<N �� X<NE
char N[0x100], D[0x100];       // rsa��N��˽Կd(256λ)
char RX[0x100], RY[0x100];     // ecc��ԿR��x���꼰y���� 
char C[2][0x100]; // �����ecc��Կ���ܹ���X, C[0]�ǵ�1��������, C[1]�ǵ�2��������
char S[2][0x100]; // �����ecnrǩ������RSA_private_encrypt_PKCS1_type_2(SHA1(X), D)
                  // ����SHA1��ɢ���㷨, RSA_private_encrypt_PKCS1_type_2()����RSA��
                  // ˽Կd��SHA1(X)���м���(ʵ������ǩ��), ����ǰ�����SHA1(X)��PKCS1_type_2
                  // ��ʽ�������, ʹ��SHA1(X)�ĳ��ȴ�20�ֽڱ��0x20�ֽ�(��256λ);
                  // ���NΪ256λ��PKCS1_type_2����ʽ����:
                  // 0x00, 0x02, 9�ֽڷ��������, 0x00, 20�ֽ�����
                  // ����������, S�Ƕ�SHA1(X)������ǩ��, ��1������rsa��˽Կǩ��, ��2������ecc��˽Կǩ��

int main()
{
    /* here is your code */
    puts(C[0]); // \\  
    puts(C[1]); //  \\ ��������Ҫ�����4��,
    puts(S[0]); //  // �������ⲻ�����б�����
    puts(S[1]); // //
    return 0;
}
