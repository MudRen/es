#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
        seteuid(getuid());
        set_name("dinosaur_act","��ʩЧ�");
        add("id",({"dino","dinosaur_act"}));
        set_short("��ʩЧ�");
        set_long(
        "����һ�ִ��ж����ҩ��, ��˵�ж����˻�Ż�²�ֹ,\n"
        "������� poison <someone> ��ĳ���¶�;�� check ���ʣ�ŵķ�����\n"
        );
        set( "unit", "��" );
        set_duration(10);
        set_effect(10);
        set_type("simple_poison");
        set_times(3);
        set_difficulty(65);
        set("poison_msg","%s������һ��.... ��~~~~\n");
        set("poison_method","%s�Ӻ�����մ��һЩ$P, ����%s");
}

