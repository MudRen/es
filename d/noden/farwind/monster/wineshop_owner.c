#include <mudlib.h>

inherit MONSTER;

void init()
{
	::init();
	add_action( "have_menu", "menu");
	add_action( "have_menu", "list");
}

void create()
{
        ::create();
        set_level( 10 );
        set_name( "wine shop owner", "�Ƶ��ϰ���" );
        add( "id", ({ "owner" }) );
        set_short( "�Ƶ��ϰ���" );
        set_long(
            "Զ����ľƵ��ϰ��"
        );
        set( "no_attack", 1 );
        set( "gender", "female" );
		set( "inquiry", ([
			"menu" :@ALONG


		����Զ��Ƶ�ļ�Ŀ�����ο�����...
		**********************************************
		*                 Զ��Ƶ�                   *
		**********************************************
		         ��Ҷ��(Ching)           20 silvers
		         �أ�(XO)                30 silvers
		         õ����(Rose wine)     20 silvers
		         ���ؼ�(Vodka)           30 silvers
		       * ����(Chicken) *        200 silvers
		       * �ص��󲹾�(Special) *  100 silvers
		**********************************************
ALONG
		]) );
}

int have_menu()
{
   write(@BLONG
   		�ϰ������һ���ֹ��ƵĲ˵����㣬�㿴�˿�...
		**********************************************
		*                 Զ��Ƶ�                   *
		**********************************************
		*         ��Ҷ��(Ching)           20 silvers *
		*         �أ�(XO)                30 silvers *
		*         õ����(Rose wine)     20 silvers *
		*         ���ؼ�(Vodka)           30 silvers *
		*         ����(Chicken)          200 silvers * 
		*       * �ص��󲹾�(Special) *  100 silvers *
		**********************************************
BLONG
        );	
	return 1;
}
