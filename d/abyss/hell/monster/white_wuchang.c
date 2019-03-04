#include <mudlib.h>
#include <ansi.h>

#define NAIHER_BRIDGE "/d/abyss/hell/bridge"
#define REVIVE_ROOM "/d/noden/farwind/cemetery"
#define JUDGE_ROOM "/d/abyss/hell/hall"
inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "White Wuchang", "���޳�" );
	add( "id", ({ "wuchang" }) );
	set_short( "White Wuchang", "���޳�" );
	set_long(
		"You see the White Wuchang, agent of the Death.\n",
		"�㿴��һ����ɫ�԰ף����ޱ���İ��¹��ˣ���������Ե����Ĺ���ʹ��\n"
		"���޳���������һλ���޳�������ȥ���������������ǰ����\n"
	);
	set( "gender", "male" );
}

void start_death(object ghost)
{
	object env;

	env = environment(ghost);
	if( !env ) return;
	if( environment() ) tell_room( environment(), ({
		"Black Wuchang says: Hmm... another one dies, what a day ....\n"
		"Black Wuchang's figure fades and disappears.\n"
		"With only one second, Black Wuchang returns with another ghost.\n",
		"���޳�˵��: �����������ˣ�������ʲ������ .....\n"
		"���޳�����Ӱ��ʧ��һƬ�����������С�\n"
		"ֻһգ�۵Ĺ��򣬺��޳���������������һ������һƬ�����г��֡�\n" }),
		this_object() );
	tell_object(ghost, can_read_chinese(ghost)?
		"\n�㿴��һ���ָ����ݵĺ�ɫ��Ӱ��������Ϣ���ߵ������� ....\n"
		"\n���޳�˵��: ���Ѿ����ˣ����Ҹ���˾����ɡ�\n"
		"\n���޳���һ���ִ����ص���������ͷ��һ�ף��ֱܴ�����������ǰ�ߡ�\n"
		"\n��ֻ����ǰ���������һ���ι��������Ȼ�������һ��ʯ�� ....\n":
		"\nYou see a tall slim figure appears behind you silently ....\n"
		"\nBlack Wuchang says: YOU HAVE DIED, MORTAL ONE.\n"
		"\nBlack Wuchang put a heavy iron chain on your neck and draw you forth.\n"
		"\nYou see many white mist fly pass your face.\n" );
	ghost->move(NAIHER_BRIDGE);
	move(NAIHER_BRIDGE);
	call_out( "death1", 10, ghost );
}

void death1(object ghost)
{
	tell_object(ghost, can_read_chinese(ghost)?
		"\n���޳�˵��: ���䣬�Ҵ�����һ�����꣬���ȥͨ��һ����\n"
		"\n���޳�תͷ����˵��: �ú�����������������κ��ž��������ˡ�\n":
		"\nBlack Wuchang says: Guards, I have brought a new ghost, announce it!\n"
		"\nBlack Wuchang turns to you and says: WAIT HERE.\n" );
	call_out( "death2", 30, ghost );
}
void death2(object ghost)
{
     tell_object(ghost,can_read_chinese(ghost)?
     "\n��������,���޳�˵��,\n":
     "\n Follow me,Black wuchang says.\n"
     );                     
    
     ghost->move_player(JUDGE_ROOM,"SNEAK");
     call_other(JUDGE_ROOM,"death3",ghost); 
}
void death3(object ghost)
{
	tell_object(ghost, can_read_chinese(ghost)?
		"\n����˵��: ���������ã�ɭ�޵�����޵��У�������ȥ�ɣ�\n"
		"\n����ץ������������һ����һ��������ת֮�ᣬ���ּ���һƬ��Ϥ�ľ��� ...\n":
		"\nHell Guard says: THE HELL IS NOT READY FOR GHOSTS, GO BACK!\n"
		"\nHell Guard throw you into the moar, you see something familiar ....\n" );
	ghost->move(REVIVE_ROOM);
	ghost->revive();
}
