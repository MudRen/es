#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("yellow roses", "��õ��");
	add ("id",({ "rose","roses"}));
	set_short("��õ��");
	set_long(
		 "����һ�������Ļ�ɫõ�廨�����ǳ�����������Ｕ�ʵ���ʹ��\n"
		 "���Ļ����ǣ����ʡ�\n"
		 "�������ϻ�ϵ��һ��С��Ƭ��\n");
	set("unit", "��");
        set ("value", ({ 10, "silver" }) );
}

