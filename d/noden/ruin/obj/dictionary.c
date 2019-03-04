// Rune Dictionary

#include "../lilia.h"

inherit OBJECT;

void init()
{
    add_action("do_read", "read");
}

void create()
{
    set_name("Rune Dictionary", "ħ���ֵ�");
    add("id", ({"dictionary", "dic"}));
    set_short("ħ���ֵ�");
    set_long(@C_LONG
���Ǵ���Ŧ˹�͸����ħ���ֵ䣬��ͷд�����������ħ������ֺ��ִ�
���ֵĶ��ձ��ֵ�������滹������ҳ�հ׵ıʼ��� (note) ��������Լ�
¼����·�������������¼��� 
C_LONG
	);
    set("unit", "��");
    set("no_sale", 1);
    set("no_drop", 1);
}

int do_read(string str)
{

    object p;
    int lv;

    p = environment(this_object());

    if (str != "note")
        return notify_fail("��ʲ��?\n");

    lv = p->query(QUESTNAME);
    if (lv)
        tell_object(p, "��ıʼ������滭����\n\n");
    else
	return notify_fail("������һƬ�հף�ʲ��Ҳû�С�\n");

    if (lv >= 7)
        tell_object(p, "������֮ӡ (Seal o Lilia)\n");
    if (lv >= 6)    
	tell_object(p, "ϣ��˹֮ӡ (Seal o Hades)\n");
    if (lv >= 5)
        tell_object(p, "������֮ӡ (Seal o Hestia)\n");
    if (lv >= 4)
        tell_object(p, "����˹֮ӡ (Seal o Furies)\n");
    if (lv >= 3)
        tell_object(p, "������֮ӡ (Seal o Persephone)\n");
    if (lv >= 2)
        tell_object(p, "����˹֮ӡ (Seal o Pallas)\n");
    if (lv >= 1)
        tell_object(p, "��ͻ��֮ӡ (Seal o Naptune)\n");

    return 1;
}
 
