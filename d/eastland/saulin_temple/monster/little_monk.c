#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(4);
        set_name( "little monk", "Сɳ��" );
        add ("id",({ "monk"}));
        set_short("Сɳ��");
        set("unit","λ");
        set_long(@C_LONG
����һλ�ܿɰ���С��������һ��СС�Ĺ�ͷ��һ��ʲ�ᶼ����������
Сɳ���Ǵ�С�ͱ��͵����ֵĺ��ӣ��ܶ඼�ǹ¶�������Ӥ��
C_LONG
        );
        set("alignment",150);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon( 6, 4, 6 );
        set_natural_armor( 20, 8 );
        set_skill("dodge",25);
        set("gender", "male");
        set("race", "human");
        set_c_verbs(({ "%s��˫����%s��ץһͨ", "%s�ö̽���%s�����߰���",
                       "%s�ù�ͷ��%s������ײȥ",
        }));
        set_c_limbs(({ "����", "��ͷ", "С��", "С��", "ƨ��", }));
#include <replace_mob.h>
}
