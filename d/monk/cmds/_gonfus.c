//#pragma save_binary

// This command is for monk only. It list all gonfus now the monk
// has learned. Created by Angel, almost rewriten by Kyoko@Eastern.Stories.

#include <mudlib.h>

inherit DAEMON;

int cmd_gonfus()
{
	int i, s;
	string *gonfu,  msg, tmp;
	mapping known, exp;

	known = (mapping)this_player()->query("monk_gonfu");
	exp = (mapping)this_player()->query("gonfus_exp");
	if( !known || sizeof(known) == 0 ) {
		write("��Ŀǰ�����κι�\��\n");
		return 1;
	}


	msg = "��Ŀǰ����ʹ�õĹ�\����:\n";
	gonfu = keys(known);
	for( i=0; i<sizeof(gonfu); i++ ) {
		if( gonfu[i] == "fist" || gonfu[i]=="heal" ) continue;
		msg +=
		sprintf("%14-s(%14-s)  ��%3d��  (��������ֵ%d) \n", to_chinese(gonfu[i]), 
         	capitalize(gonfu[i]),  known[gonfu[i]], ( exp ? exp[gonfu[i]] : 0 )) ;
       }

	if( gonfu = known["fist"] ) {
		tmp = "\n����ȭ��: " ;
		for( i=0; i<sizeof(gonfu); i++ )
			tmp += 
				sprintf("%s(%s), ", to_chinese(gonfu[i]), gonfu[i]) ;
		msg += iwrap(tmp, 60);
	}
	if( gonfu = known["heal"] ) {
		tmp = "\nҽ���ķ���ָ��: " ;
		for( i=0; i<sizeof(gonfu); i++ )
			tmp += 
				sprintf("%s(%s), ", to_chinese(gonfu[i]), gonfu[i]) ;
		msg += iwrap(tmp, 60);
	}
        if ( this_player()->query("monk_score") ) {
	msg += sprintf("\n������ֵĹ��׹�\���� %d ��\n\n",(int)this_player()->query("monk_score"));
                                                   }
	write(set_color(msg,"GRN",this_player()));
	return 1;
}

int help()
{
	write( @HELP
�÷� : gonfus
���ָ����г�Ŀǰ����ͨ���Ĺ����Լ��ȼ�������Ҳ���г���Ŀǰ�������µ�
���׶ȡ�

�ο� : fist
HELP
	      );
	return 1;
}
