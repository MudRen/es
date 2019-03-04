//#pragma save_binary

#include <mudlib.h>
#include <ansi.h>

inherit DAEMON;

int cmd_shout(string str)
{
	int i, tp,woman;
	object me, *urs;
	string name, c_name, verb, str1, str2, msg, msg_me, color,c_you;

	me = this_player();
	urs = users();
	urs -= ({ me });
	
	name = capitalize((string)me->query("name"));
	c_name = (string)me->query("c_name");
	c_you = ((string)me->query("gender")=="female"? "��":"��") ;

	if( me->query_level() < 3 ) return notify_fail( 
		"�ܱ�Ǹ��Ϊ�˱�����������ɧ�ţ��ȼ������µ���Ҳ�׼ʹ�� shout ָ�\n");

	if ( me->query_temp("shoutter")) return notify_fail ( 
		"��ող������ļ�й����� .. ���ǲ�Ҫ���С���̫Ƶ�� ..\n");

	if( !str || str=="" ) return notify_fail( 
		"��Ҫ��ʲ�᣿\n");

	tp = (int)me->query("talk_points");

	if( !wizardp(me) && tp < 50 ) return notify_fail( 
		"���Ѿ��е�̫���������������ٺ�����Ϣ�°ɡ�\n");

	str = replace_string(str,ESC,"");
	if( msg = me->query_env("C_MSHOUT") ) {
		if( sscanf(msg, "%s$N%s", str1, str2) == 2 ) {
			msg = sprintf("%s%s(%s)%s : ",
				  str1,c_name,name,str2);
//			msg_me = sprintf("%s%s%s : ",str1,c_you,str2 );
		} else {
			msg = sprintf("%s(%s)%s : ",c_name,name,msg);
//			msg_me = sprintf("%s%s : ",c_you,msg);
		}
	} else {
		msg = sprintf("%s(%s)���� : ",c_name,name);
//		msg_me = sprintf("%s���� : ",c_you);
	}
	
	color = me->getenv("ENV_COLOR");
	if( !color ) color = "HIR";
	for( i= sizeof(urs)-1 ; i>=0; i-- ) {
		if( !environment(urs[i]) ) continue; 
		urs[i]->quick_message(sprintf("%s%s\n",set_color(
			 msg , color, urs[i]),str) );
	}
	printf("%s%s\n",set_color(c_you+"���� : ", color),str);

	if( !wizardp(me) ) {
		me->add( "talk_points", -50 );
 		me->set_temp("shoutter",1);
		call_out("recover_shout",1,me);
	}

	return 1;
}

void recover_shout(object me)
{
	if ( !me ) return ;
	me->delete_temp("shoutter");
	return;
}
int help()
{
   write(@HELP
ʹ�ø�ʽ: shout <��Ϣ>

���ڹ㲥���ʣ�������3���µ���Ҳ���ʹ��.
ͬʱʹ��ʱ����20��̸��ֵ��Ϊ0ʱ���޷�ʹ��.
HELP
);
   return 1;
}