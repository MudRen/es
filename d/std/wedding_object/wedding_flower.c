
#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name("wedding flower", "��������");
	add( "id", ({ "flower" }) );
	set_short("wedding flower", "��������");
	set_long("..",
	"����ϸ�Ŀ������������������ŵ�һ������.....\n"
	"��������ᣬ�����͸���һλ��Ҫ����Ů���ɡ�\n");
	set("unit","��");
        set("no_sale",1);
        set( "weight", 10 );
        set( "value", ({ 50, "silver" }) );
}
