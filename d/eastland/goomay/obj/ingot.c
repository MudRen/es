#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("broken symbol","����Ľ���");
        add( "id" , ({ "symbol" }) );
        set_short("����Ľ���");
        set_long(@LONG
����һ���ƾɵĽ��ƣ���������������������ƣ���֪����ʲ�ᶫ����
�����ܱ�ʶ��ԭ��ģ����ֻ�о���ḻ�ĵ��̻��ǹŶ����ϰ��ˡ�
LONG
	);
        set("unit","��");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
