#include <../zeus.h>
inherit MONSTER;

void create()
{
        ::create();
        set_level(7);
        set_name( "invalid", "����" );
        add("id",({"invalid"}));
        set_short( "����");
        set("unit","λ");
        set_long( @LONG
����һλȫ������������ˣ����ڲ������е����ĵؿ����컨�壬Ҳ\��\����
�ڴ�����������������������Ӧ�û������������(hurt)����������
LONG
        );
        set_perm_stat("str",12 );
        set_natural_weapon(12, 6, 12);
        set_natural_armor( 40, 20 );
        set ("gender", "male");
        set ("race", "dwarf");
        set_c_verbs(({"%s�����Ĺ�����%s��ȥ","%s�����Ľ���%s��ȥ","%s������ȭͷ��%s����"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon( ZOBJ"/stick" );

        set("inquiry",([
        "detonation":"@@ask_detonation", 
        "hurt": 
                "�����������Ǵδ�ը�б����˵ģ�\n"
      ]));
}
int ask_detonation()
{
tell_object(this_player(),
@AA
���˵���˵����Ҳ��Ī�������һ���Ҹպ�Ҫ�Ͷ�������ͷ��ԶԶ
��ֻ�Ƽ���ͷ��֪����ȼ��ʲ�ᶫ����������һ�� (throw)�����һ
��������ʱ�����������ˣ�
��������Ƕ�����������Ĵ����ң���Ϊ��Ҳ������Ҳ������������
��ϣ�������ҵ����࣡
AA
);
this_player()->set_temp("get/paper_torch",1);
}