#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("laurel", "�¹�Ҷ");
	add ("id",({ "laurel"}));
	set_short("�¹�Ҷ");
	set_long(
		 "����һ���ҷ����¹�Ҷ�����ǳ����������������кͶ�Ӣ�۵ĳ羴��\n"
		 "���Ļ����ǣ������������塢���ݵ�Ӣ�ۡ�\n"
		 "�������ϻ�ϵ��һ��С��Ƭ��\n");
	set("unit", "��");
        set ("value", ({ 10, "silver" }) );
}

