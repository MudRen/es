#include <mudlib.h>
inherit ARMOR;
void create()
{
	seteuid(getuid());
	set_name("night cloth","ҹ�з�");
	add("id",({"cloth"}));
	set_short("ҹ�з�");
	set_long(@LONG
����һ��������ɫ�·�, ʹС͵��ҹ��ʱ�����׵������Լ���
�·��������ڴ�, ���Է�С��, ������, ��˿��С�ɵĹ��ߡ�
LONG
	);
	set("unit","��");
	set("weight",40);
	set("type","body");
	set("material","thief");
	set("armor_class",15);
	set("defense_bonus",5);
	set("value",960);
}
