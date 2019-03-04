// This is a spell object. type -> misc
// level    0
// cost   180
// time    60
// skill   80
// G_LVL    0	ע: ħ�������ȶԱ��������κ�Ӱ��
// G_EXP   50
#include <mudlib.h>
#define TYPE "misc"
#define GATE "/d/magic/misc/gate.c"

inherit DAEMON;
inherit "/d/magic/magic";
inherit MESSAGE;

int query_gain_spell_exp(int level) { return 50; }

int query_need_spell_level(int level) { return 0; }

int query_sp_cost(object caster, int level) { return 180; }

int query_need_skill(int level) { return 80; }

int cast(int level, string dest)
{
    object me;
    string area;
	
	me = this_player();
     
	if( (int)me->query_skill("misc") < query_need_skill(level) ) {
	  tell_object( me, 
		      "�������ħ�����ܲ�����ʹ�����ħ��! \n" 
		      );
      return 0;
    }

if ( !environment(me)->query("outside") )
        {
                tell_object( me, "���￴��������, û�취�����ǿ�֮�š�\n");
                return 0;
        }
        if ( environment(me)->query("no_teleport") )
        {
                tell_object( me, "�������޷����ܵ����ϵ�����, �޷������ǿ�֮�š�\n");
                return 0;
        }

	if (!dest) return 0;
	if (!dest = me->query( "teleport_points/" + dest ) )	{
		tell_object( me, "��û���κι������ǵļ���, �޷������ǽ�֮��\n" );
		return 0;
	}

         area=explode(dest,"/")[2];
          if((area== "island")||(area== "beggar")||(area== "story")||(area== "legend"))
	{     tell_object( me, "���������ʱ�ر�! \n");
	     return 0;
	}

	emote( @TEXT
$NS�����������ġ���˹. �Ͽ���. ������.... ����֮Ը�����֮��,
׷������֮��... �������ǽ�֮�š�
TEXT
		, this_player() );

	call_out( "open_gate", 2, dest, this_player() );
    gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	return 1;
}

void	open_gate(string dest, object caster)
{
	object	dest_room;
	object	gate, back_gate;
	
	if (!caster) return;
	dest_room = find_object_or_load( dest );
	if ( (!dest_room) || ( environment(caster)->query("no_teleport") ) ||
		(dest_room->query("no_teleport")) )
	{
		tell_room( environment(caster), 
			"һ������ɫ�Ĺ��Ÿ���������ǰ, ����ת�ۼ��Ť������ʧ�ˡ�\n"
		);
		return;
	}
	
	gate = clone_object( GATE );
	back_gate = clone_object( GATE );
	gate->set_destination( dest_room );
	back_gate->set_destination( environment(caster) );
	gate->move( environment(caster) );
	back_gate->move( dest_room );
	tell_room(  environment(caster), 
		"һ��ҫ�۵�����ɫ��������ǰ�滺��������\n"
	);
	tell_room(  dest_room, 
		"һ��ҫ�۵�����ɫ��������ǰ�滺��������\n"
	);
	call_out( "remove_gates", 60, gate, back_gate);
}

void	remove_gates( object gate, object back_gate )
{
	if	(gate) gate->remove();
	if	(back_gate)	back_gate->remove();
}
