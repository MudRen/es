//#pragma save_binary

// _hp.c
// Command to show a player's hit points.
// Created by Mobydick@TMI-2, 9-23-92
// And spell points, as of 11-16-92
// Add acupuncture condition for healers. By Indra@EasternStory 4-26-95

#include <mudlib.h>
#include "/d/healer/healer.h"

inherit DAEMON;

int help();

string query_color(int now, int max)
{
	int percent;
	
	percent = now * 100 / max;
	switch( percent ) {
		case  0..20 : return "HIR";
		case 21..40 : return "HIM";
		case 41..64 : return "HIY";
		case 65..90 : return "HIG";
			default : return "HIC";
	}
}

int cmd_hp()
{
	int max, flag,i,limit;
	object me;
	string msg,cond_str,acup_str,*cond_name,*acup_name;
	mapping conds,acups ;
	me = this_player();
	msg = "";
		if( max = me->query("max_hp") ) {
			flag = me->query("hit_points");
			msg = sprintf(sprintf(" ��  ��  :   %s/%s",set_color("%4d", query_color(flag,max))
				,set_color("%4d\n", "HIC")), flag, max);
		}
		if( max = me->query("max_sp") ) {
			flag = me->query("spell_points");
			msg = sprintf(sprintf("%s ������  :   %s/%s",msg,set_color("%4d", query_color(flag,max))
				,set_color("%4d\n", "HIC")),flag, max);
		}
		if( max = me->query("max_fp") ) {
			flag = me->query("force_points");
			msg = sprintf(sprintf("%s ��  ��  :   %s/%s",msg,set_color("%4d", query_color(flag,max))
				,set_color("%4d\n", "HIC")),flag, max);
		}
		if( max = me->query("max_tp") ) {
			flag = me->query("talk_points");
			msg = sprintf(sprintf("%s��̸���� :   %s/%s",msg,set_color("%4d", query_color(flag,max))
				,set_color("%4d\n", "HIC")), flag, max);
		}
/*		if( max = me->query("max_ap") ) {
			flag = me->query("action_points");
			msg = sprintf(sprintf("%s�ж����� :   %s/%s",msg,set_color("%4d", query_color(flag,max))
				,set_color("%4d\n", "HIC")), flag, max);
		}
*/
	conds = me->query("conditions");
        cond_str = "";
        if( sizeof(conds) ) 
          {
            cond_name = keys(conds);
	    for( i=0, limit=sizeof(cond_name); i<limit; i++ ) {
                if( cond_name[i][0] == '_' ) continue;
                cond_str = sprintf("%s %s", cond_str, to_chinese(cond_name[i]));
  	       }
	   }
	if( cond_str == "" ) cond_str = " �� ��";
	msg = sprintf("%s ״  ̬  :   %s\n",msg,cond_str);

        acups = (mapping)me->query_temp("acup_effect");
        if((string)me->query("class")=="healer")
          {
           acups = (mapping)me->query_temp("acup_effect");
           acup_str = "";
           if ( sizeof(acups) ) 
              {
                   acup_name = keys(acups);
                   for( i=0, limit=sizeof(acup_name); i<limit; i++ )
                       {
                           if( acup_name[i][0] == '_' ) continue;
                           acup_str = sprintf("%s %s", acup_str,
                              USE_POINTS->query_effect_c_name(acup_name[i]));
                       }
              }
           if ( acup_str == "" ) acup_str = " û�а��" ;
           msg = sprintf("%s���Ч�� :   %s\n",msg,acup_str);
           }        
        
        me->quick_message(msg);
	return 1;
}

int help() {
	write (@HELP
ʹ�ø�ʽ: hp

���ָ���ʾ�����������������̸���ȸ������ֵ.
HELP
);
	return 1 ;
}
