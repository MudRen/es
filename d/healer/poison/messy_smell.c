#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
        seteuid(getuid());
        set_name("messy_smell","��ҹ����");
        add("id",({"messy","smell"}));
        set_short("��ҹ����");
        set_long(
        "����һ�ִ���Ũ��������ҩ��\n"
        "������� poison <someone> ��ĳ���¶�;�� check ���ʣ�ŵķ�����\n"
        );
        set( "unit", "��" );
        set_duration(10);
        set_effect(5);
        set_type("confused");
        set_times(1);
        set_difficulty(40);
        set("poison_method","%s�Ӻ�����մ��һЩ$P, ����%s");
}

