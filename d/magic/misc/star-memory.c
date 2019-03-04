// This is a spell object. type -> misc
// level    0
// cost    50
// time    --
// skill   80
// G_LVL   --	ע: ħ�������ȶԱ��������κ�Ӱ��
// G_EXP   30
#include <mudlib.h>
#define TYPE "misc"

inherit DAEMON;
inherit "/d/magic/magic";
inherit MESSAGE;

int query_gain_spell_exp(int level) { return 30; }

int query_need_spell_level(int level) { return 0; }

int query_sp_cost(object caster, int level) { return 50; }

int query_need_skill(int level) { return 80; }

int cast(int level, string dest)
{
    object me;
	
	me = this_player();

	if( (int)me->query_skill("misc") < query_need_skill(level) ) {
	  tell_object( me, 
		      "�������ħ�����ܲ�����ʹ�����ħ��! \n" 
		      );
      return 0;
    }

	if (!dest) {
		tell_object( me, "����ѹ������ط��ļ���ķ���������?\n" );
		return 0;
	}
	switch (dest)
	{
		case "aqua"		: break;
		case "pyro"		: break;
		case "aero"		: break;
		default	:	{
			tell_object(me, @FAIL
����֮�䡹���Խ����й�춴˵صĻ���ķ�����ϵ��ǳ�, ���ǽ���ˮ֮
�� (Aqua) ��֮�� (Pyro) ���֮�� (Aero) ��ӵ���㹻�������������
���˼����
ָ���ʽ: cast star-memory [on|at] <�ǳ�>
FAIL
			);
			return 0;
		};
	}

	if ( !environment(me)->query("outside") )
	{
		tell_object( me, "���￴��������, û�취ʹ����֮�䡣\n");
		return 0;
	}	
	if ( environment(me)->query("no_teleport") )
	{
		tell_object( me, "�������޷����ܵ����ϵ�����, �޷����¼��䡣\n");
		return 0;
	}
	
	emote( "$NS��ͷĬ������, �����й�춴˵صļ���ϵ������ϵ����ǡ�\n"
		, me );

	me->set("teleport_points/" + dest, base_name(environment(me)) );
    gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	return 1;
}
