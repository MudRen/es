// Archfiend
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name("Archfiend", "����ʹ ����ҵ�");
    add("id", ({"archfiend", "devil"}));
    set_short("����ʹ ����ҵ�");
    set_long(@C_LONG
��Ц����ף������ĳ�����ͷ�ϵ���ֻ�ǣ�����˵��Ҳ֪��վ������
ǰ����ڤ�����ϴ����ʹ����ҵ£���������ı��ǡ�������Ҫ�߳������
��������˼�̸�ʽ��� (trade) �ųɡ�
C_LONG
	    );
    set("gender", "male");
    set("race", "vampire");
    set("unit", "λ");
    set("no_attack", 1);
    set("inquiry", ([
	"trade" : "@@ask_trade",
	"dedicate" : "@@ask_dedicate",
	"question" : "@@ask_question"
	]) );
}

void init()
{
    ::init();
    add_action("to_answer", "answer");
}

void ask_trade(object p)
{
    tell_object(p, @TRADE
����ҵ�б���۴��������һ�����Ȼ������˹���˵���������������߸���
ӡ��ȥ���Ǹ���̬Ů����? ���������ɼ�ѽ! Ϊ�˱�ʾ�Ҷ����ߵĳ羴�����
��ѡ������������ (dedicate) ��ħ�����ǻش��ҵ����� (question)
���õ������еĸ���˹֮ӡ���������Ⱦ����㣬�����û�а취��ȷ�ػش���
�����⣬����������Զ��ط��׸�ħ��������Ҳ�ò�������˹֮ӡ�����
���Ҫ��������� .... ���㵽��Զ��������Ȼ�����׺Ǻǡ���������֮�ᣬ
�� (ask) �ҷ��� (dedicate) ������ (question)����
TRADE
	       );
    return;
}

void ask_dedicate(object p)
{
    tell_object(p, "����ҵ´�Ц�������ø�ˬ��ļһ�һ�к��޳��ø���˹ӡ���㣡��\n");
    this_player()->set(QUESTNAME, 4);
    tell_object(p, "һ�����������Ȼ����������ϣ���е���ǰһ�� ...\n");
    tell_room(environment(p), "����ҵ·�����һ���Ц���漴�ٻ���һ������ֱֱ������"+p->query("c_name")+"�����ϣ�\n", p);
    this_player()->receive_damage(2000);
    return;
}

void ask_question(object p)
{
    tell_object(p, @QUES
����ҵ�˵������ֻҪ������ң��������������̬����ʦ��˭����ԵĻ���
�Ҿ������ҵ�ŵ�ԡ��㲻�ؼ����ش��ң���Ȼ������˵Ļ�������븶�����
���������ۡ���
QUES
	       );
    this_player()->set_temp("lilia_devil", 1);
    return;
}

int to_answer(string s)
{
    object p;
    p = this_player();

    if (!s || p->query_temp("lilia_devil") != 1 || p->query(QUESTNAME) >= 4)
	return notify_fail("�����ʲ�᣿\n");

    if (s != "lilia" && s != "����ʦ" && s != "Ů��")
    {
	tell_object(p, "����ҵ´�Ц����������򵥵���ĿҲ���᣿��������\n");
        tell_object(p, "һ�����������Ȼ����������ϣ���е���ǰһ�� ...\n");
        tell_room(environment(p), "����ҵ·�����һ���Ц���漴�ٻ���һ������ֱֱ������"+p->query("c_name")+"�����ϣ�\n", p);
        p->receive_damage(2000);
    }
    else
    {
	tell_object(p, @LAUGH
����ҵ´�Ц�����������ļһһƨ�е������Ѿ��������ҵ�ŵ�ԣ�
�Ѹ���˹ӡ�͸����ˡ�˳������ɳ��˹������ˣ���Ҫ�Ǻã���������
���Ҫ����Ů������ǰ����ȥ�ɣ������ļһ��
LAUGH
		   );
	tell_object(p, "����ҵ�ž��һ������ͷ�ϴ���һ�ǣ��������ǰһ�� ....\n");
        write("[������� ʧ��ķ�ӡ �ڶ��׶ε����񣬻�� 2000 �㾭��]\n");
        this_player()->finish_quest(QUESTNAME, 2);
        this_player()->gain_experience(2000);
	this_player()->set(QUESTNAME, 4);
	p->move(AREA"rose4");
    }

    return 1;
}   
