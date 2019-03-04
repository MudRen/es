#include <mudlib.h>

inherit MONSTER;

void init()
{
	add_action( "have_menu", "menu");
	add_action( "have_menu", "list");
}
void create()
{
        ::create();
        set_level( 7 );
        set_name( "the wine shop owner", "������ƹ�" );
        add( "id", ({ "owner" }) );
        set_short("������ƹ�" );
        set_long(
@LONG
����һ����ʮ������������ˣ�������Ʋϡϡ�����С���ӣ�����һ��ո��
���޳��۵���Ц����ĺͽ������Ŀ���������к������������Խ������Խ
æ��  
LONG
        );
        set( "gender", "male" );
	set("race","human");
	set( "alignment",200);
        set_natural_armor( 34, 14 );
        set_natural_weapon( 8, 8, 16 );
	set( "wealth/gold",10);
        set_perm_stat( "str", 12 );
        set_perm_stat( "int", 10 );
        set_perm_stat( "dex", 10 );
        set_skill( "unarmed", 50 );
        set_skill( "parry", 50 );
        set( "hit_points", 200 );
        set( "max_hp", 200 );
        set( "special_defense", ([ "all": 20 ]) );
	set( "defense_type","parry");
}

int have_menu()
{
		write(@MENU
�ƹ��Ц����ĵ���һ���ֹ��ƵĲ˵����㣬�㿴�˿�...
**********************************************
*               ����ӾƵ�                   *
**********************************************
         ��Ҷ��(Ching)           20 silvers
         �أ�(XO)                30 silvers
         õ����(Rose wine)     20 silvers
**********************************************
MENU
	);
	return 1;
}
