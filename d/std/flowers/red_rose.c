#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("red roses", "��õ��");
        add ("id",({ "rose","roses"}));
	set_short("��õ��");
	set_long(
		 "����һ�������ĺ�ɫõ�壬���ǳ�����������ﰮ�顣\n"
		 "���Ļ����ǣ��Ȱ���\n"
		 "�������ϻ�ϵ��һ��С��Ƭ��\n");
	set("unit", "��");
        set ("value", ({ 10, "silver" }) );
}

