#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("ironweed", "��Է��");
        add ("id",({ "ironweed"}));
	set_short("��Է��");
	set_long(
		 "����һ����������Է�ݣ����ǳ����������������µĻ��䡣\n"
		 "���Ļ����ǣ�������εΡ�\n"
		 "�������ϻ�ϵ��һ��С��Ƭ��\n");
	set("unit", "��");
        set ("value", ({ 10, "silver" }) );
}

