#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(9);
        set_name( "worker leader", "�ܹ�" );
        add ("id", ({ "leader","worker" }) );
        set_short("�ܹ�");
        set("unit","λ");
        set_long(@C_LONG
���ǹܹ�����ƽ�յ�ְ���Ƕ��ٳ�����Ҫ͵����������������һ��Ƥ�ޣ�
�������װͰ͵ġ�
C_LONG
        );
        set("alignment",-200);
        set("wealth/silver",100);
        set_perm_stat("str", 13);
        set_perm_stat("dex", 12);
        set_natural_weapon( 7, 0, 4 );
        set_natural_armor( 45, 16 );
        set_skill("whip", 50);
        set ("gender", "male");
        set ("race", "human");
        set ("pursuing",1);
        set ("chat_chance",12);
        set ("chat_output",({
        "�ܹ�˵������Щ��������ó����������ҷ�ʱʱ�������ǲ��ɣ������ᡣ\n",
        }));
        wield_weapon(SAULIN_OBJ"knout");
}
