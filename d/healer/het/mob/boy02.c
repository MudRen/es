#include "mudlib.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(4);
        set_name( "little boy", "ͯ��" );
        add ("id",({ "boy"}));
        set_short( "ͯ��");
        set("unit","λ");
        set_long("",
@C_LONG
����һ��ʮ���ĺ��ӣ���û����ʵ�����ҩ¯������¯�����е�����
ż�����һ��, ��ͣ�ˡ��������ĵ�����, ����ϣ�������������İɡ�
C_LONG
);
        set("alignment",0);
        set("wealth/silver",15);
        set_perm_stat("str",10);
        set_perm_stat("dex",8);
        set_perm_stat("kar",8); 
        set_natural_weapon(5,3,6);
        set ("natural_armor_class", 20);
        set_skill("dodge",35);
	set("defense_type","dodge");
        set("natural_defense_bonus",2);
        set ("gender", "male");
        set ("race", "human");
	 set( "inquiry" , ([
		"wang" : "ʦ�����鷿Ъ��, ��������?",
		"herb" : "����ҩ��ͨ����������..�ϴ�ȥ��ҩ����㱻����ҧ����\n",
		"oven" : "ʦ������ҩ���������¯�����ġ�\n", 
		"painting" : "@@ask_painting",
	]));
       
}

void ask_painting(object who)
{
	tell_object(who, 
"����˵ʦ��ǽ�ϹҵĻ���? �Դ�����������, ʦ�����������ǻ���������һ����\n"
"�߽��鷿��, ʦ������, ���ǹ�һ���ȴ���鷿�߳��� ... ������ \n"
	);
}


