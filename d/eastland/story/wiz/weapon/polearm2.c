#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden polearm","�ƽ�ì");
	add ("id",({ "polearm"}) );
        set_short("�ƽ�ì");
	set_long(@C_LONG
����һ��ȫ����ɫ�ĳ�ì����Ȼ�����������أ�ǰ��ìͷȴ�쳣��������ʧΪһ
�Ѻ�������  
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("polearm", 33,19,33);
	set( "weight", 200 );
	set( "value", ({ 5000, "silver" }) );
}

