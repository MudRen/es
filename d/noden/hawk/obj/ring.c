
#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("blue ring", "����ɫ���ջ�");
	seteuid(getuid());
        add( "id", ({ "blue ring","ring" }) );
        set_short( "����ɫ���ջ�" );
        set("long","����һö����ɫ�Ľ�ָ�����������ά���ᰮ\n");
        set( "weight", 3 );
        set( "unit", "ö" );
}
