#include <mudlib.h>
#include <ansi.h>

#define NAIHER_BRIDGE "/d/abyss/hell/bridge"
#define REVIVE_ROOM "/d/noden/farwind/cemetery"

inherit MONSTER;

void op_revive1(object ghost);
void op_revive2(object ghost);

void create()
{
	::create();
	set_level(13);
	set_name( "Black Wuchang", "���޳�" );
	add( "id", ({ "wuchang" }) );
	set_short( "���޳�" );
	set_long( @LONG
�㿴��һ����ɫ�԰ף����ޱ���ĺ��¹��ˣ���������Ե����Ĺ���ʹ��
���޳���������һλ���޳�������ȥ���������������ǰ����
LONG
	);
	set( "gender", "male" );
}

void start_death(object ghost)
{
	object env;

	if( ! ghost ) return;
	env = environment(ghost);
	if( !env ) return;
	if( environment() ) tell_room( environment(), @DIE1
���޳�˵��: �����������ˣ�������ʲ������ .....
���޳�����Ӱ��ʧ��һƬ�����������С�
ֻһգ�۵Ĺ��򣬺��޳���������������һ������һƬ�����г��֡�
DIE1
		,this_object() );
	tell_object(ghost, @DIE
�㿴��һ���ָ����ݵĺ�ɫ��Ӱ��������Ϣ���ߵ������� ....
���޳�˵��: ���Ѿ����ˣ����Ҹ���˾����ɡ�
���޳���һ���ִ����ص���������ͷ��һ�ף��ֱܴ�����������ǰ�ߡ�
��ֻ����ǰ���������һ���ι��������Ȼ�������һ��ʯ�� ....
DIE
	);
	ghost->move(NAIHER_BRIDGE);
	move(NAIHER_BRIDGE);
	if (ghost->query_temp("operate")) call_out( "op_revive1", 5, ghost);
	else call_out( "death1", 5, ghost );
}

void death1(object ghost)
{
	if ( ! ghost ) return;
	tell_object(ghost, @DEATH1
���޳�˵��: ���䣬�Ҵ�����һ�����꣬���ȥͨ��һ����
���޳�תͷ����˵��: �ú�����������������κ��ž��������ˡ�
DEATH1
		    );
    if (ghost->query_temp("operate")) call_out( "op_revive1", 5, ghost);
	else call_out( "death2", 20, ghost );
}

void death2(object ghost)
{

	if ( !ghost) return;
	if (ghost->query_temp("operate")) {
	   op_revive1(ghost);
	   return;
	}   
	tell_object(ghost, @DEATH2
����˵��: ���������ã�ɭ�޵�����޵��У�������ȥ�ɣ�
����ץ������������һ����һ��������ת֮�ᣬ���ּ���һƬ��Ϥ�ľ��� ...
DEATH2
		);
	ghost->move(REVIVE_ROOM);
	ghost->revive(0);
}

void op_revive1(object ghost)
{
     if (!ghost) return;
     if (! (ghost->query_temp("operate") ) ) {
        call_out("death2",20,ghost);
        return;
     }
     tell_object(ghost, @OP_REV1
�㿴�����ܿ����Ĺ��, ���������������������, ��ļ�ͥ, ��
����ҵ....����, �㻹��̫������Ų���, �����Ҫ����������
����
OP_REV1
     );
     call_out("op_revive2",20,ghost);
}

void op_revive2(object ghost)
{
     string healer;
     object healer_obj;
     if (!ghost) return;
     if (! (healer=ghost->query_temp("operate") ) ) {
        tell_object(ghost,"��, ����̫������, ���Ҳ�����������!\n");
        death2(ghost);
        return;
     }
     if (! (healer_obj=find_player(healer) ) ) {
         death2(ghost);
         return;
     }
     tell_object(ghost, @OP_REV2
�㷢�ֿ�����Ĺ������ڴ��˯, ���̰��ջ����ͷ����....
����, ţͷ����, �ڰ��޳��������Ằ��, ׷����, ���㲻�������, һ��
ֻ����������....
���Ȼһ��̤��, ��һƬ������ˤ������, �����ֻص�����Ϥ��Ӱ��
OP_REV2
      );
      
      ghost->move(environment(healer_obj));
	  ghost->revive(1);
}                 
