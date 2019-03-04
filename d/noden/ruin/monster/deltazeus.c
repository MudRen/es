// Adventurer Delta Zeus
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    seteuid(getuid());
    set_level(1);
    set_name("Delta Zeus", "����ѧ�� ����Ŧ˹");
    add("id", ({"delta", "zeus"}));
    set_short("����ѧ�� ����Ŧ˹");
    set_long(@C_LONG
վ������ǰ����λ���������Ƕ��������Ŀ���ѧ���Ŵ���Ŧ˹��Ҳ�Ǹ�
�ǳ�������ð�ռҡ�����Ŧ˹����ǰЩ����Ϊ�˿��鴫˵�е�ħ��ŵ۹��ż�
��ʧ���ˣ�û�뵽���������������������������й��ż� (ruin) ������
������һ����СС�ĺ����ġ�
C_LONG
	    );
    set("gender", "male");
    set("race", "human");
    set("unit", "��");
    set("no_attack", 1);
    set("inquiry", ([
	"ruin" : "@@ask_ruin",
	"rune" : "@@ask_rune"
	]) );
}

void ask_ruin(object p)
{
    tell_object(p, @RUIN
�ż�? �ǺǺ� .... �����ˣ������ھ�վ��ħ��ŵ۹���һ�����˹����
�ǵ���������! ������ħ��ŵ۹����¼�����Ȥ�Ļ�����������õĽ��ң�
���ǵ�Ҫ���Լ�Ŭ��ȥѰ�Ҳ��С�
RUIN
	);
    return;
}

void ask_rune(object p)
{
    object dic, *items;
    int i;

    tell_object(p, @RUNE
Ŷ���Ǹ����İ�? ���ǹŴ�ħ������֣���������ֻд���ĸ��֣���֥��
���š����һ�û���ó���������˼�ء������ˣ�������ħ��ı�������Ȥ��
�Ȿħ���ֵ��͸��㣬�����԰������Ķ�ħ��Ĺ��ġ�
RUNE
	);
    items = all_inventory(p);
    for (i = 0; i < sizeof(items); i++)
   	if ((string)items[i]->query("name") == "Rune Dictionary")
	{
	    tell_object(p, "��? ���Ѿ����Ȿ�ֵ���? ���һ����������ˡ�\n");
	    return;
	}

    dic = new(OBJ"dictionary");
    dic->move(p);
    p->set_temp("lilia_dic", 1);
    return;
}

