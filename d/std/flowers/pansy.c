#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("pansy", "��ɫ��");
	add ("id",({ "pansy"}));
	set_short("��ɫ��");
	set_long(
		 "����һ����������ɫ�������ǳ������������˼��֮�⡣\n"
		 "���Ļ����ǣ�˼�\n"
		 "�������ϻ�ϵ��һ��С��Ƭ��\n");
	set("unit", "��");
        set ("value", ({ 10, "silver" }) );
}

