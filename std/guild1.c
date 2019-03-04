//#pragma save_binary
 
// guild.c
// Written by Mobydick@TMI-2, 11-15-92
// Almost rewritten by Annihilator@Eastern.Stories, 10-26-93
// Please leave the credits part of this header in place.
// You can delete the rest of it.
 
#include <daemons.h>
#include <stats.h>
#include <explore.h>
#include <mudlib.h>
#include <move.h>
#include <org.h>
 
inherit ROOM;
 
// The variable trainable_skills stores the skills which this guild can
// train you in.
 
string this_guild;
 
void set_guild(string guild);
 
int do_list(string arg);
int do_cost(string arg);
int do_advance(string arg);
int do_train(string arg);
int do_help(string arg);
int do_explore(string area);

// This function announce all member of this guild some message.
void announce_guild_members(string type, object me)
{
        string *master, gclass, c_msg;
        object *urs;
        int i;
        
        urs = users();
        master = this_guild->query_guild_master();
        if( !master ) master = ({ "Master", "�����ϴ�" });
        gclass = (string)me->query("organization");
        c_msg = "["+to_chinese(gclass)+"] "+master[1]+" : ";
        if( type == "join" ) {
                c_msg += "��ӭ "+me->query("c_name")+"("+me->query("name")+") "+
                  "��ʽ�������ǵ�����!\n";
        } else return;
        for( i=0; i<sizeof(urs); i++ )
                if( this_guild->is_guild_member(urs[i]) )
                        urs[i]->quick_message(c_msg);
}

// This function sets the classes that are allowed to train/advance in
// the guild. If you pass the string argument ALL, then all classes can
// train/advance here. Otherwise, you should pass an array of strings 
// containing the names of classes that are allowed to train/advance
// in this guild.

void set_guild(string guild)
{
        if( file_size(guild)>0 )
                this_guild = guild;
        else
                this_guild = GUILD_MASTER(guild);
}

// Init adds the cost and train commands. You must call this if you
// add your own init functions. (i.e. you must call guild::init();
// in the init() of your guild.

void init()
{
        add_action("do_cost", "cost");
        add_action("do_list", "list");
        add_action("do_advance", "advance");
        add_action("do_train", "train");
        add_action("do_join", "join");
        add_action("do_verify", "verify");
        add_action("do_help", "help");
        add_action("do_explore", "explore");
        add_action("do_quests", "quests");
}

int do_list(string arg)
{
        int i;
        string msg, *skills;

        skills = this_guild->query_skill_list();
        msg = "������������ѵ���ļ�����:\n";
        for( i=0; i<sizeof(skills); i++)
                        msg += sprintf("    %-30s ( ����ֵ���� = %3d%%, ���� = %3d )\n", 
                                to_chinese(skills[i]) + "("+skills[i]+")",
                                this_guild->query_skill_cost(skills[i]),
                                this_guild->query_skill_max(skills[i]) );
        write(msg);
        return 1;
}
int query_org_exp(int lv)
{
	int i,exp;
	if(lv>MAX_ORG_LEVEL) lv= MAX_ORG_LEVEL;
	if(lv<0) lv=0;
	exp=LOW_ORG_EXP;
	for(i=0;i<lv;i++)	exp+=exp/3;
	return exp;
}

int query_exp_train(object me)
{
	int lv, exp;
	lv = (int)me->query("level");
	exp = (int)me->query_experience() - query_org_exp(lv-1);
	return exp;
}

int query_org_quest(object me)
{
	int lv, quest;
	lv = (int)me->query("level");
	if(lv<0) lv=0;
	quest = LOW_ORG_QUEST+lv*LEVEL_UP_QUEST;
	return quest;
}
int query_org_explore(object me)
{
	int lv,expl;
	lv = (int)me->query("level");
	if(lv<0) lv=0;
        expl = LOW_ORG_EXPLORE + lv*LEVEL_UP_EXPLORE;
	if(expl>1000) expl=1000;
	return expl;
}

int do_cost(string arg)
{
        int i, exp, lvl, s, stock, none;
        string *attrs, *skills, msg;
        object me;

        me = this_player();
        if( !this_guild->is_guild_member(me) )
                return notify_fail("�ܱ�Ǹ���㲻���������ĳ�Ա��\n");

        lvl = me->query("level");
        exp = query_org_exp(lvl) - (int)me->query_experience();

        if( lvl >= MAX_ORG_LEVEL ) msg ="���Ѿ�������߼��ˡ�\n";
        else if( exp > 0 ) msg ="�㻹��Ҫ "+exp+" �㾭�����������\n";
        else msg = "��ľ���ֵ�Ѿ��ﵽ������׼�ˡ�\n";
                
        stock = query_exp_train(me);
        if( stock < 1 ) 
                msg +="��Ŀǰû���κζ���ľ�����������������ܡ�\n";
        else 
	{
              msg +="�������� "+stock+" �㾭����������������ܡ�\n";

              none = 1;
                msg += "ѵ������ :";
                skills = this_guild->query_skill_list();
                for( i=0; i<sizeof(skills); i++) {
                        s = (int)me->query_perm_skill(skills[i]);
                        exp = this_guild->query_skill_exp_cost(skills[i], s);
                        if( exp > 0 ) {
                            none = 0;
                                msg +=sprintf("\n    %30-s -> %2d    %d �㾭�顣",
                                              to_chinese(skills[i])+"("+skills[i]+")", s+1, exp) ;
                        }
                }
                if( none )
          msg +=" ��ļ��ܾ��Ѵﱾ�������ֵ�ˡ�\n" ;
        else msg += "\n";
        }
        write(msg);
        return 1;
}


int do_advance(string arg)
{
    mapping quests;
        int lvl, stat, exp, chinese_mode,expl,max;
        object me;
        string *attrs;
		string msg;
		sprintf("test");
        me = this_player();
        chinese_mode = can_read_chinese();
		//write(chinese_mode);

      if( me->id("guest") )
              return notify_fail("�ܱ�Ǹ, GUEST ���������κεȼ���\n") ;
              
        if( !this_guild->is_guild_member(me) )
                return notify_fail("�ܱ�Ǹ���㲻���������ĳ�Ա��\n");

        
        // prevent wrong keyin, added by Kyoko.
        if( !arg ) return do_help("advance");
        //if( !arg ) return notify_fail("test��\n") ;
        // Advance attribute?

        if( arg == "level" ) {
                lvl = (int)me->query("level");
				//by ca
				msg="level=";
				msg+=sprintf("%d\n",lvl);
				write(msg);
				//end
                if( lvl >= MAX_ORG_LEVEL )
                        return notify_fail("���Ѿ�������߼��ˡ�\n");
                        
                // check exp...
                exp =  query_org_exp(lvl);
				// by ca
				msg="exp=";
				msg+=sprintf("%d\n",exp);
				write(msg);
				//end
                if( exp > (int)me->query_experience() ){
					//by ca
					msg="exp=";
					msg+=sprintf("%d\n",(int)me->query_experience());
					write(msg);
//end
                        return notify_fail("��ľ���ֵ������������׼��\n");
				}

                // check quest point, added by Kyoko.
                if( query_org_quest(me)>me->query_quest_points())
                        return notify_fail("��Ǹ, ����������������������׼��\n");

                // check explored, add by Kyoko.

                expl = (int)me->query_explore_points();
                max = (int)EXPLORE_D->query_total_explore();
                if( max < 1 ) expl = 0;
                  else expl = expl * 1000 / max;
                if( expl > 1000 ) expl = 1000;

                if( expl < query_org_explore(me) )
                      return notify_fail("��Ǹ, ���̽�նȻ�δ�ﵽ������׼���ٶ�ȥ���ɡ�\n");

        }
	lvl=me->query("level");
	lvl++;
	me->set("level",lvl);
        write(sprintf("�������ǵ� %d ���ˡ�\n",lvl));
        me->set("title",me->query_title());
        tell_room( environment(me), 
                  sprintf("%s�����ǵ� %d ���ˡ�\n",
                           me->query("c_name"),lvl) , me );
        return 1;
}

int do_train(string arg)
{
        int exp, skill;
        object me;

        me = this_player();
        if( !this_guild->is_guild_member(me) )
                return notify_fail("�ܱ�Ǹ���㲻�������֯�ĳ�Ա��\n");

        if( !arg || !this_guild->query_skill_exp_cost(arg,0) )
                return notify_fail("���� list ָ��쿴���������ṩ��ѵ�����ݡ�\n");

        skill = (int)me->query_perm_skill(arg);
        exp = this_guild->query_skill_exp_cost(arg, skill);

        if( exp < 1 )
                return notify_fail("���"+to_chinese(arg)+"�����Ѿ��ﵽ���ֵ�ˡ�\n");

        if( exp > query_exp_train(me) )
                return notify_fail("��ľ���ֵ������\n");

        if( skill >= ((int)me->query("level") * LEVEL_UP_SKILL+LEVEL_UP_SKILL) )
                return notify_fail("�ܱ�Ǹ����Ŀǰ�ĵȼ�ֻ��ѵ����Ŀǰ���ֵز���\n");

        me->gain_experience( -exp );
        STATS_D->train_skill( me, arg );
                printf( "���%s�������������� %d �ˡ�\n", to_chinese(arg), me->query_perm_skill(arg));
        return 1;
}

int do_join(string arg)
{
        object ob, token,me;
        int join_ok,exp,expl,max,lvl;

        if( arg ) return 0;

        ob = this_player();
        if( this_guild->is_guild_member(ob) )
                return notify_fail("���Ѿ��Ǳ�����ĳ�Ա�ˣ�\n");
        
        if( ob->id("guest") )
              return notify_fail("Guest ���ܼ����κι��ᡣ\n") ;

        // Check if the player is a wizard or didn't join other guilds yet.
        if( wizardp(ob) ) {
                join_ok = (int)this_guild->join_player(ob);
                if( join_ok ) announce_guild_members("join", ob);
                return join_ok;
        } else if(ob->query("level")>0)
               return notify_fail( "���Ѿ����������������ˣ��������˳�ԭ���Ĺ��ᣡ\n");
        else  {

	        me=ob;   
                exp =  query_org_exp(0);
                if( exp > (int)me->query_experience() )
                        return notify_fail("��ľ���ֵ̫�͡�\n");

                // check quest point, added by Kyoko.
                if( query_org_quest(me)>me->query_quest_points())
                        return notify_fail("����������̫�͡�\n");

                // check explored, add by Kyoko.

                expl = (int)me->query_explore_points();
                max = (int)EXPLORE_D->query_total_explore();
                if( max < 1 ) expl = 0;
                  else expl = expl * 1000 / max;
                if( expl > 1000 ) expl = 1000;

                if( expl < query_org_explore(me) )
                      return notify_fail("���̽�ն�̫�ס�\n");

             }
             join_ok = (int)this_guild->join_player(ob);
             if( join_ok ) 
	     {
               announce_guild_members("join", ob);
               ob->set("title",this_guild->query_c_title(ob));
             }

             return join_ok;
}


int do_explore(string arg)
{
        int expl, max, i, need_exp;
        object me;
        
        me = this_player();
        need_exp = query_org_explore(me)/10 ;
        if( need_exp < 0 ) need_exp = 0;
        if( !this_guild->is_guild_member(me) )
                return notify_fail("�ܱ�Ǹ�����ﲢû��������ϣ���ص��Լ��Ĺ����ѯ̽�նȡ�\n");

        for( i=0; i<sizeof(AREAS); i++ ) {
                expl = (int)me->query_explore_points(AREAS[i]);
                max = (int)EXPLORE_D->query_total_explore(AREAS[i]);
                if( max < 1 ) continue;
                expl = expl * 1000 / max;
                if( expl > 1000 ) expl = 1000;
                printf("���� : "+set_color("%13s", "HIG")+"    ̽�ն� : "+
                        set_color("%2d.%1-d%%\n", "HIY"),
                        to_chinese(AREAS[i]), expl/10, expl%10);
        }
        expl = (int)me->query_explore_points();
        max = (int)EXPLORE_D->query_total_explore();
        if( max < 1 ) expl = 0;
        else expl = expl * 1000 / max;
        if( expl > 1000 ) expl = 1000;
        printf(set_color("ƽ��̽�ն� : %2d.%1-d%%    ������׼��%d%%.\n","HIC"), 
                         expl/10, expl%10,need_exp);
    return 1;
}

int do_quests(string arg)
{
        string *sloved;
        int i,size_quest;
        object me;

        me = this_player();
        if( !this_guild->is_guild_member(me) )
                return notify_fail("�ܱ�Ǹ�����ﲢû��������ϣ���ص��Լ��Ĺ����ѯ��\n");

        sloved = me->query_finish_quests();
        if( !sloved || !( size_quest=sizeof(sloved) ) )
                write(set_color("��Ŀǰ��δ����κε�����, �ӵ��Ͱ�!\n", "HIR"));
        else {
                for( i=0; i<size_quest; i++ )
                        printf("������� "+set_color("%s", "HIG")+
                                   " ������\n", to_chinese( sloved[i] ) );
                printf( "���õ� %3d ������������\n" ,(int)me->query_quest_points());
        }
    return 1;
}

int do_verify(string arg)
{
       this_guild->check_token(this_player());
       return 1;
}
int do_help(string arg)
{

        switch(arg) {
                case "guild": write( @C_USAGE_GUILD
�����������ʹ�����µ�ָ�ÿһ��ָ��и��꾡��˵��( ���� "help <ָ��>" ):

  list        - �г������������ܽ���ѵ���ļ�����Ŀ��
  cost        - �г��������������ԡ���ѵ����������ľ���ֵ��
  advance     - �����ȼ�, ����ȼ������ԡ�
  train       - ѵ�����ܡ�
  join        - ����������ᣬ��ĵȼ�����С� 5 �����ܼ��빫�ᡣ
  explore     - ��Ѱ��Ŀǰ��ð�նȡ�
  quests      - �г�����ɵ���������

C_USAGE_GUILD
                        ); break;
                case "list": write( @USAGE_LIST
ָ���ʽ: list

    ���ָ�����г������������ܽ���ѵ���ļ�����Ŀ��
USAGE_LIST
                        ); break;
                case "cost": write( @USAGE_COST
ָ���ʽ: cost

    ���ָ������ʾ�������������ԡ���ѵ����������ľ���ֵ��
USAGE_COST
                        ); break;
                case "advance" : write( @USAGE_ADVANCE
ָ���ʽ: advance level 

    ����ľ���ֵ�㹻ʱ�����ָ����������ĵȼ������ǣ����
���̽�նȼ��������δ���׼ʱ����ʹ����ֵ�㹻�಻��������
USAGE_ADVANCE
                        ); break;
                case "train": write( @USAGE_TRAIN
ָ���ʽ: train <����>

    ����ӵ���㹻�ľ���ֵʱ�����ָ����������ļ��ܡ�
USAGE_TRAIN
                        ); break;
                case "join": write( @USAGE_JOIN
ָ���ʽ: join

    ���ָ�����������������ᡣ����Ҫע����ǣ�ĳЩ�������ǰ�������Ҫ
��߱�ĳЩ�ض���������������ָ�info�����õ��й���������һЩ��Ѷ��
USAGE_JOIN
                        ); break;
                case "info": write( @USAGE_INFO
ָ���ʽ: info [<����>]

    ���ָ���ܸ���һЩ�й�����������õ���Ѷ�����������������һ������ǰ
��һ��Ҫ���Ķ���Щ��Ѷ������ָ�info������û��ָ������Ļ��������һ��
����������б�
USAGE_INFO
                        ); break;
        case "explore": write( @USAGE_EXPLORE
ָ���ʽ: explore

    ���ָ���ܲ�Ѱ��Ŀǰ��ð�նȡ�
USAGE_EXPLORE
                        ); break;
        case "quests": write( @USAGE_QUESTS
ָ���ʽ: quests

    ���ָ�����г�������ɵ���������
USAGE_QUESTS
                        ); break;
                default:
                        return 0;
        }
        return 1;
}
