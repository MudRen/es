#include "mudlib.h"
#include "../wang.h"
inherit MONSTER ;

void create ()
{
	object ob;

        ::create();
        set_level(3);
        set_name( "little boy", "ͯ��" );
        add ("id",({ "boy"}));
        set_short( "ͯ��");
        set("unit","λ");
        set_long(
@C_LONG
����һ���߰����ĺ��ӣ��������ڵ������⻨�ԡ�����СС���
ȴ�ܰ�����Ū��ǬǬ�����ģ����ǲ��򵥡�
C_LONG
);
        set("alignment",150);
        set("wealth/silver",15);
	set_perm_stat("dex",7);
	set_perm_stat("str",7);
        set_natural_weapon(4,3,5);
        set ("natural_armor_class", 20);
        set_skill("dodge",35);
	set("defense_type","dodge");
        set("natural_defense_bonus",2);
        set ("gender", "male");
        set ("race", "human");
	ob = new(ITEM"key");
	ob->move(this_object());
}
