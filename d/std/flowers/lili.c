#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("lily", "�װٺ�");
	add("id",({"lily"}) );
	set_short("�װٺ�");
	set_long(
		 "����һ֧���¸��ŵİװٺϣ����ǳ������������紿������Ů��\n"
		 "���Ļ����ǣ�������а��\n"
		 "��֧���ϻ�ϵ��һ��С��Ƭ��\n");
	set("unit", "֧");
        set ("value", ({ 10, "silver" }) );
}
