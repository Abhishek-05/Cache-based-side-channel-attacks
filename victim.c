#include <stdio.h>
#include <string.h>
#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <openssl/pem.h>


int main(){
    char privkey[] = {
        "-----BEGIN DSA PRIVATE KEY-----\n"
        "MIH4AgEAAkEA3F41fxvcwGZeFxXg2v0/5SR+cxTizT25QugwZgrC7u2zQYTO1Qu0\n"
        "PPDKUrLxkaLzKsUEJbQ1DImnG/FxtRjH7QIVAOp+o1qPhOI4DtnvYS86ynTxhDcF\n"
        "AkAyKbiUxJigARuuVVlGn4emXOtrT+Al+gmKbbVFfkS62RhSZexQ9+mBLv0/1R8T\n"
        "k37AwuybnflijiPjLxB1ZL00AkA2DXjw+0PJOyrQfn2Q44uHyZMG2WfXqT7CIz26\n"
        "ZiIAHDOkZQhOvPLqCKAXfwHgGrgl2JLovhVY8nPMdNk2vJijAhUAzK9TuVobhOE8\n"
        "kU0xl8lqaI/PMyg=\n"
        "-----END DSA PRIVATE KEY-----"
        };

    char pubkey[] = {
        "-----BEGIN PUBLIC KEY-----\n"
        "MIHwMIGoBgcqhkjOOAQBMIGcAkEA3F41fxvcwGZeFxXg2v0/5SR+cxTizT25Qugw\n"
        "ZgrC7u2zQYTO1Qu0PPDKUrLxkaLzKsUEJbQ1DImnG/FxtRjH7QIVAOp+o1qPhOI4\n"
        "DtnvYS86ynTxhDcFAkAyKbiUxJigARuuVVlGn4emXOtrT+Al+gmKbbVFfkS62RhS\n"
        "ZexQ9+mBLv0/1R8Tk37AwuybnflijiPjLxB1ZL00A0MAAkA2DXjw+0PJOyrQfn2Q\n"
        "44uHyZMG2WfXqT7CIz26ZiIAHDOkZQhOvPLqCKAXfwHgGrgl2JLovhVY8nPMdNk2\n"
        "vJij\n"
        "-----END PUBLIC KEY-----"
        };

    char message[] = {"Hello World!"};

    //save message for console test
    FILE *message_file = fopen ("message.txt","w");
    fwrite(message, strlen(message), 1, message_file);
    fclose(message_file);

    //save private key for console test
    FILE *privkey_file = fopen ("privkey.pem","w");
    fwrite(privkey, strlen(privkey), 1, privkey_file);
    fclose(privkey_file);

    //save public key for console test
    FILE *pubkey_file = fopen ("pubkey.pem","w");
    fwrite(pubkey, strlen(pubkey), 1, pubkey_file);
    fclose(pubkey_file);

    //Prepare sign  -----------------------------------------------------

    BIO *priv_bio;
    priv_bio = BIO_new_mem_buf(privkey, -1); 
    if(priv_bio == NULL){ERR_print_errors_fp(stdout);return 1;}

    DSA *private_key;
    private_key = PEM_read_bio_DSAPrivateKey(priv_bio, NULL, NULL, NULL); 
    if(private_key == NULL){ERR_print_errors_fp(stdout);return 2;} 

    unsigned int result, sign_length;
    unsigned char signature[1000] = {0};

    //generate sign
    // while(true){
    result = DSA_sign(0, (const unsigned char*)message, strlen(message),
                    (unsigned char*)signature, &sign_length, private_key);
    // }
    printf("%d\n",result);
    if(result!=1){ERR_print_errors_fp(stdout);return 3;}

    return 0;
}