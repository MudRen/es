#include "saulin_temple.h"

inherit ROOM;
int got;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
һ����С�������С��װ�����һ�����֣�����������������������֣�
�ഫÿһλ��ɮ�����������õ������Ӷ��Ὠһ��С������ţ�����������
���������������ֵ���ʷ�ƾ����˲ű���Ϊʲ�������������
C_LONG_DESCRIPTION
	);
	got=0;
    set_outside("eastland");
	set( "exits", ([
		 "north" : SAULIN"towers4",
      	 "east"  : SAULIN"towers4",
		 "west"  : SAULIN"towers3",
		 "south" : SAULIN"towers5",
	]) );
	reset();	
}

void init()
{
	add_action( "summon_seed", "call" );
        if (this_player()) this_player()->set_explore("eastland#32");
}

int summon_seed(string arg)
{
	if( !arg || arg=="" || arg !="relic")
	{
 		tell_object(this_player(), 
    		"һ��������翵�������: ���й�и�ʲ�ᾢ��\n" 
   		);
	return 1; }
	if ( got ) {
        tell_object(this_player(), 
        	"����˺ð��죬������Ӱ��Ҳû�С�\n" 
        );
	return 1; }
        tell_object(this_player(),@GOT_SEED
����˼�����ͻȻһ�������Ĺ�����������������һ�ӣ���Ȼ�ǿ������ӡ�
GOT_SEED
		);
		got=1;
   		new( SAULIN_OBJ"magic_seed" )->move( this_player() );
  	return 1;
}

void reset()
{
    ::reset();
	got=0;
}
