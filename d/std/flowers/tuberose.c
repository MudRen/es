#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("tuberose", "ҹ����");
        add ("id",({ "tuberose"}));
	set_short("ҹ����");
	set_long(
		 "����һ���ҷ�������ҹ���㡣\n"
		 "���Ļ����ǣ�Σ�յĿ��֡�\n"
		 "�������ϻ�ϵ��һ��С��Ƭ��\n");
	set("unit", "��");
        set ("value", ({ 10, "silver" }) );
}

