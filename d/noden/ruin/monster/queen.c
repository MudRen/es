// Lilia the Queen
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Lilia the Queen", "Ů�� ������");
    add("id", ({"lilia", "queen"}));
    set_short("Ů�� ������");
    set_long(@C_LONG
���ϵ����������ϵģ���ؾ��Ǵ�˵�е�ħ�������Ů����������������
ɫ���Ǻܺã��ƺ���̫��������ˡ������������Ů�����ʹ���һ����������
��һ�㡣
C_LONG
	    );
    set("gender", "female");
    set("race", "drow");
    set("unit", "��");
    set("no_attack", 1);
    set("inquiry", ([
	"airshield" : "@@ask_airshield",
	"home" : "@@ask_home"
	]) );
}

void init()
{
    add_action("to_cheer", "cheer");
}

int to_cheer(string arg)
{
    if (arg == "lilia" || arg == "queen" || arg == "Ů��")
    if ((int)this_player()->query(QUESTNAME) == 7)
    {
 	write("Ů���������ͷ��˵���������Ǹ��ú��ӡ���\n");
	write("[������� ʧ��ķ�ӡ �����񣬻�� 3000 �㾭��]\n");
	this_player()->finish_quest(QUESTNAME,3);
	this_player()->gain_experience(3000);
	this_player()->set(QUESTNAME, 9);
	return 1;
    }

    write("Ů��˵������Ҫ������ؼ� (home) ֱ˵�ͺ�����������ƨ�ˡ���\n");
    return 1;
}

void ask_airshield(object p)
{
    if ((int)p->query(QUESTNAME) != 9)
    {
	tell_object(p, "Ů��б��������һ�£�Ȼ���û���κη�Ӧ�ˣ������������ƺ���̫�á�\n");
	return;
    }

    if (p->query("class") != "healer")
    {
	tell_object(p, "Ů����������һ�£�˵�������㲻��ҽ�������ⶫ����ʲ�᣿��\n");
	return;
    }

    p->set(QUESTNAME, 8);
    tell_object(p, "Ů��˵�������Ժ��ӣ������Ҵ͸������ (amass) ����������Ҫ�ú�����Ӵ����\n");
    tell_room(environment(p), "Ů���૵��������� ....\n", ({}));
    tell_object(p, "��ʱ�䣬��ͻȻ��ᵽ�������Գɶܵĵ�����ѧ������������\n");
    return;
}

void ask_home(object p)
{
    tell_object(p, "Ů��˵�������ú��ӣ�����ɳ��ȥ�����ϵ���ˣ�ɣ���\n");
    tell_object(p, "Ů������˵�꣬���Ȼ������ǰһ�� ....\n");
    p->move("/d/healer/building/healer_guild");
    return;
}
