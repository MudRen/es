//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int help();
/*
int cmd_eujian(string str)
{
	object me,weapon;
	mapping where;
	int i;
	string msg,dest,*node_name,first,second,n,d;
	
	me = this_player();
	weapon = (object)me->query("weapon1");
	
        if ( !str ) return help();
        
        if ( !weapon || (string)weapon->query("type") != "longblade" ) 
        	return notify_fail( "��û���ʵ�������Ү !!\n" );
        
        if ( me->query_attackers() )
        	return notify_fail( "ι !! �㻹��ս����Ү���뱻�������� ??\n" );
        	
        if ( me->query("gonfu_busy") || me->query_temp("gonfu_busy") ) 
        	return notify_fail( "������ʹ��������\�������޷�Ԧ����\n" );
        
	if ( str == "where" ) {
		where = (mapping)me->query("node");
		
		if (!where || sizeof(where) == 0 ) {
			write("�㲻�ǵ��κεط�����Ԧ����ȥ��\n");
			return 1; }
		else {
		
		msg = "��Ŀǰ�ǵõĵط��� : \n" ;
		
		node_name = keys(where);
		for( i=0; i < sizeof(node_name); i++ ) 
			msg += sprintf("  %d : %s\n", i+1, node_name[i]);
		write(msg);
		return 1; } 
		}
	if ( sscanf(str, "%s %s", first, second) ) {
		write(first+second+"\n");	
		n = (string)environment(me)->query("short");
		d = base_name(environment(me));
		
		if ( first == "here" ) {
			where = (mapping)me->query("node");
		
			if (!where || sizeof(where) == 0 ) {
				me->set("node/"+n, d);
				return 1; }
			} 
		else return help(); } 
	
        if ( str == "guild" ) {
        	tell_object( me,
        		"��۾�����Ĭ������\춽����ϣ�����һ��Ŀ�ĵط�ȥ !!\n" );
 		tell_room( environment(me), 
 			sprintf("%s��������������һ��Զ����ȥ !!\n", me->query("c_name")), me );       		
        	me->move_player( "/d/scholar/scholar/scholar_guild", "SNEAK" );
        	tell_room( "/d/scholar/scholar/scholar_guild", 
        		sprintf("һ������ɫ�Ľ�������%s���� !!\n", me->query("c_name")), me );
 		return 1; }      
	return 1;
}
*/

int help()
{
		write( @C_HELP
ָ���ʽ: eujian <����>

���ָ����������Ԧ�����С�����Լ������еĲ��� :

	where       :     �г���Ŀǰ���ǵõĵط���
	guild       :     �ɻع��ᡣ
	here 1,2,3  :     ��ס�˵ء�
	1,2,3       :     Ԧ�����Ƕ��� 
C_HELP
		);
    return 1;
}
