////#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int cmd_aid(string arg)
{
	object dest;
	int hp, max_hp, skill ;
        string target,target1,myname ;

        if( this_player()->query("stop_attack")!=0) 
             return notify_fail( "����ϸ�������û���,�޷�ʩ�м��ȡ�\n" );

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "��Ҫ��˭ʩ�м��ȣ�\n" );

	if( !living(dest) ) 
		return notify_fail( "�Ǹ�������������Ҫ���ȡ�\n" );
        
        target  = dest->query("c_name") ;
        target1 = dest->query("c_name") ;
        
	if( dest->query("ghost") ) return notify_fail( 
		sprintf("̫���� .... %s�Ѿ����ˡ�\n",target ) );
	if( dest->query("no_aid") ) return notify_fail(
	        dest->query("c_name") +
	        "Ц������˵:лл��ĺ���, ���������б�Ҫʱ, ���Լ����ֿ��ܱȽϺá�\n"
	);	
        if( dest->query_current_attacker()!=0) 
             return notify_fail( "���Ŀ������ս����,���޷��������ȡ�\n" );

	hp = (int)dest->query( "hit_points" );
	max_hp = (int)dest->query( "max_hp" );

//   ��̫�����ܶ��Լ�����...

	if( dest==this_player()&& hp < max_hp/6 ) 
               return notify_fail( "������̫�ض��޷����Լ�ʩ�м��ȡ�\n" );        

        if(dest == this_player())
           {
               target = "�Լ�" ;
               target1 = "���Լ�" ;
            }                    

	if( hp==max_hp ) return notify_fail( 
		sprintf( "%s��û�����ˡ�\n",target1 ) );

	if( dest->query_temp("aided") ) return notify_fail( 
		sprintf( "%s�Ѿ������ȹ��ˡ�\n",target1 ) );

	if( hp > max_hp/3 ) return notify_fail(
		sprintf("%s�����ƻ�û�����ص���Ҫ���ȵĵز���\n",target1) );

	skill = (int)this_player()->query_skill( "first-aid");
	if( !skill ) return notify_fail( 
		"�㲢û��ѧ�����ȵļ��ܡ�\n");


	write(sprintf("���%s���м��� ....\n",target1) );

        myname = this_player()->query("c_name") ;
        
        if(dest != this_player())
     	    tell_object( dest, 
		sprintf("%s������м��� .... ����úö��ˣ�\n",myname ) );

	tell_room( environment(this_player()), 
		sprintf("%s��%s���м��� ....\n",myname,target),
		({ this_player(), dest }) );
		
	if( dest!=this_player() ) this_player()->add( "alignment", 25 );
	dest->receive_healing( skill/2 + random(skill/2) );

 //    ���ȶ�������ֻ�ܼӵ�һ��� HP
	hp = (int)dest->query( "hit_points" );
        if( !wizardp(this_player()) && hp > max_hp/2 ) 
           dest->set("hit_points",max_hp/2) ;

	dest->set_temp( "aided", 1 );
	this_player()->receive_experience( skill );
	call_out( "remove_aided", 300, dest );
    return 1;
}

void remove_aided(object player)
{
	if( player ) player->set_temp("aided", 0);
}

int help()
{
    write(
    @C_HELP
ָ���ʽ: aid <ĳ��>

���ָ�������ĳ������( �� NPC )ʩ�м��ȣ��йؼ��ȵ�ϸ�����������
�� help first-aid��
C_HELP
	);
    return 1;
}
