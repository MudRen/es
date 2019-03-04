#include "mudlib.h"

inherit OBJECT;

string *c_illusion =({
"˯�����㿴��һֻ�򡢶�ֻ����ֻ����ֻ��...Խ��Խ�����������ȥ��\n",
"˯�����㿴���Լ�վ��һ������Сɽ��΢Ц��ԭ�����µĶ����Լ��Ľ�����\n",
"˯�����㿴���Լ����ϵ��ź�����ɱѽ��ɱѽ���������һ��.....\n",
"�㿴��һλȫ������������ʿ���ǧ�������г�̣�ȡ�����׼���������֮�أ�\n",
"˯�����㿴��һλͷ���й�Ȧ�ĸ�ɮ��������һ�������书\����������Ħ������\n",
"˯�����㿴��һλ������ˣ�����Ҧ٬��Ůħ��ʦ��Ц������˵�����ˣ���˧�磡��\n",
"�������˳�����Ҫ����ʱ������񿴵�һ����Ӱ��Ȼ�ᷢ��Ǯ�����ˣ����Ǻ��ܣ�\n",
"�㿴��һλ�����������轣����Ӱ���棬�����������Ҹ����ǻ�������Ӱ���ң���\n",
"˯�����㿴��һλȫ������������˺������в�����������ƽ���ܶ�������ͣ���\n",
"˯�����㿴��һֻ������Сè����������������ү��ɱ��...С�ĸ�����¿�ͷ����\n",
"�㿴��һֻ��̬�����ܳ�������˵����Ҫ�ӣ�ƫƫע��Ҫ��������û�ˣ�Ǯû��..��\n",
 }) ;

//int maxhp,maxsp,maxtp,hp_full,sp_full,tp_full ;

void create()
{
        set_name( "Bed", "�о���" );
//        set( "id", ( { "bed" } ) );
        set_short( "�о���" );
        set("unit", "��" );
        set_long( "����һ���о���, �����������˯��\n" );
        set( "weight", 100000);
}

void init()
{
add_action("cmd_sleep","sleep");
// add_action("cmd_out","out");
// add_action("cmd_quit","quit");
add_action("cmd_wake","wake");
add_action("cmd_protect","protect");
add_action("cmd_unprotect","unprotect");
add_action("cmd_kill","kill");
}
void do_sleep(object player, int skill, int degree,int num )
{ 
   string text;
   string *colors = ({ "HIC", "HIY", "HIB" });
   int i, maxhp, maxsp, maxtp, hp_full, sp_full, tp_full;
   if ( degree < 10 && skill > random(degree*10) && (int)this_player()->query_temp("shaked") < 1) { 
           if (degree > 2) i = random(8)+2 ; else i = degree ;
           text = c_illusion[i];
           message("illusion", 
              set_color(text, colors[random(3)], player),player) ;
           if (degree % 2) {
             tell_room( environment(player), 
             sprintf("�㿴�� %s ���ڴ��ϣ�һ��������ˮ��һ�ߴ������˵�������\n",
               player->query("c_name")), player );
           } 
           maxhp = (int)player->query("max_hp"); 
           maxsp = (int)player->query("max_sp"); 
           maxtp = (int)player->query("max_tp");     
           player->add("hit_points", num + 1);
           player->add("spell_points", (int)num/2 + 1 );
           player->add("talk_points", (int)num/2 + 1 );
           if ((int)player->query("hit_points") >= maxhp) {
              player->set("hit_points",maxhp) ;
              hp_full = 1 ;
           } 
           if ((int)player->query("spell_points") >= maxsp) {
              player->set("spell_points",maxsp) ;
              sp_full = 1 ;
           }
           if ((int)player->query("talk_points") >= maxtp) {
              player->set("talk_points",maxtp) ;
              tp_full = 1 ;
           } 
           call_out( "do_sleep", 8, player, skill, degree + 1,num );
   } else {
       player->delete_temp("block_command");
       tell_object( player, 
		"......ͻȻ��������һ��������������Ը�����˹�����\n" );
       tell_room( environment(player), 
       sprintf("�㿴��%s���������۾��������������������\n",
               player->query("c_name")), player );
       call_out("quit_camp", degree*20, player);
   }
}

void quit_camp( object player )
{
        if( !player ) return;
        tell_object( player,
                "��о���һ�����ˡ�\n");
        player->delete_temp("in_sleep");
}

int cmd_sleep()
{
    int skill, hp, num;
    object me,env;
	
    me = this_player();
    env = environment(me) ;
    skill = (int)me->query_temp("build_skill");
//    maxhp = (int)me->query("max_hp"); 
//    maxsp = (int)me->query("max_sp"); 
//    maxtp = (int)me->query("max_tp");     
//    sp_full=0; hp_full=0; tp_full = 0 ;
    num = me->query_temp("camp_size");
    if ( me->query("class") == "adventurer" )
    num = num +1;  
    if (me->query_temp("in_sleep")) {
    write("����������˯������˯��\n");
    return 1;
    }
    if( (int)me->query_attacker()) {
      write("��ս����˯������Ҫ���Ϻ��ݲ���\n");
      return 1;
    }
    tell_object( me,
                    "��ʵ��̫���ˣ�����Ҹ��յص�ͷ��˯��\n" );
    tell_room( env, 
	me->query("c_name")+"�ƺ�̫���ˣ�һ���������ڴ��ϲ���˯�ߡ�\n",
		me );
    if( !wizardp( me ) ) {
	me->set_temp("in_sleep",1);
	me->set_temp("block_command", 1 );
    }		
    me->set_temp("shaked",0);
    call_out( "do_sleep", 8, me, skill, 0, num );
    return 1;
}

int cmd_wake(string arg)
{
     object target,me;
     me = this_player();
     if ( !arg || arg == "") {
                      tell_object( me,
                      "���Ѿ����˰�?\n" );
                      return 1;
                      }
    
     if ( !(target = present( arg,environment(this_player()))) ) {
                      tell_object( me,
                      "����û�н�"+arg+"�Ķ�����\n");
                      return 1;
                      }
    
     if ( !visible(target,this_player()) || target->query("invisible_player")) {
                      tell_object( me,
                      "����û��������?\n");
                      return 1;
                      }
     
     if ( !living(target) || !(int)target->query_temp("block_command")==1 ) {
                      tell_object( me,
                      "��������ҡ��"+target->query("c_name")+"����ʲ����Ҳû������\n");
                      return 1;
                      }      
      tell_object( me, set_color(
           "�������ҡ��" + target->query("c_name") + "�����壬��ͼ��������...\n\n", "HIY"
           ,me) );
                      
      tell_object(target, set_color(
           me->query("c_name")+"������ҡ���������.....\n\n", "HIM"
            ,target));
                                              
      tell_room( environment(me), "\n"+
           me->query("c_name")+"����ҡ��"+
           target->query("c_name")+"�����壬��ͼ��������\n\n" ,
           ({ me, target }) );
      
      target->set_temp("shaked",1); 
      target->delete_temp("block_command");
      target->receive_special_damage("none",20);
      return 1;
   }  
int cmd_protect(string str)
{
	object damsel,*prot,*prot2;
	string *foo;
	int	i;

        if ((string)this_player()->query("class") != "adventurer" ) 
              return notify_fail("ֻ��ð����������������������...\n");
        prot = (object *)this_player()->query_temp("protect_whom");

	if (!str) {
		if ( sizeof(prot) < 1 )
			return notify_fail("������û�б����κ��ˡ�\n");
		prot2 = ({ }) ;
		for ( i=0 ; i < sizeof(prot) ; i++) 
			if ( !nullp(prot[i]) && prot[i]) prot2 += ({ prot[i] }) ;
		prot = prot2 ;
		this_player()->set_temp("protect_whom",prot);
		write(set_color("�����ڱ����� :\n","HIY",this_player()));
		for ( i=0 ; i < sizeof(prot) ; i++)
			write(sprintf("%s(%s)\n",prot[i]->query("c_name"),prot[i]->query("name")));
		return 1;
	}

	damsel = present(str, environment(this_player())) ;
//	if ( damsel = this_player() )
//	        return notify_fail("�����Լ����㻹�����\n");
	if (!damsel || !living(damsel))
		return notify_fail("��Ҫ����˭��\n");

        if( prot && pointerp(prot) ) {
                if ( member_array( damsel,prot ) != -1 )
                return notify_fail("���Ѿ����������� !!\n");
		if (sizeof(prot) > 3 )
		return notify_fail("�㲻�ܷ��ı���������� !!\n");
	}

	write( sprintf("������˾�����ע��%s�İ�ȫ��\n",damsel->query("short"),to_chinese(subjective(damsel))));
	tell_object( damsel, 
		sprintf("%sĿ��ת����ע������İ�ȫ��\n",this_player()->query("c_name")));

	damsel->add_temp("who_protect", ({ this_player() }) ) ;
	this_player()->add_temp("protect_whom", ({ damsel }) ) ;
	return 1 ;
}
int cmd_unprotect(string str)
{
	object *foo, *tmp, me;
	int i, j, done;

	if( !str ) return 0;
	me = this_player();
	if ((string)this_player()->query("class") != "adventurer" )
	            return notify_fail("ֻ��ð����������������������...\n");
	foo = (object *)me->query_temp("protect_whom");
	if( sizeof(foo) < 1 )
		return notify_fail("�����ڲ�û�б����κ��ˡ�\n");
	done = 0;
	for( i=sizeof(foo)-1; i>=0; i-- ) {
		if ( !foo[i] ) continue ;
		if( !foo[i]->id(str) ) continue;
		write(sprintf("��ֹͣ����%s(%s)��\n", foo[i]->query("c_name"),
				foo[i]->query("name")));
		tell_object( foo[i], 
			sprintf("%s(%s)ֹͣ�����㡣\n", me->query("c_name"),
				me->query("name")));
		tmp = foo[i]->query_temp("who_protect");
		tmp -= ({ me });
		foo[i]->set_temp("who_protect", tmp);
		foo[i] = 0;
		done++;
	}
	if( done ) {
		if( sizeof(foo) > done ) {
			done = 0;
			tmp = allocate(sizeof(foo)-done);
			for( i=sizeof(foo)-1; i>=0; i-- ) {
				if( foo[i] == 0 ) continue;
				tmp[j] = foo[i];
				j++;
			}
			me->set_temp("proctect_whom", tmp);
		} else me->delete_temp("protect_whom");
	} else return notify_fail( 
		"�����ڲ�û�б����κν��� " + str + " ���ˡ�\n");
	return 1;
}
int cmd_kill(string arg)
{ 
       object me, victim, *protector;
       int i,kar;
       me = this_player();
       kar = this_player()->query_perm_stat("karma");
       if( !arg ) return 0; 
       if ( !( victim = present( arg,environment(me))) ) return 0;
       if ( !living(victim)) return 0;                
       protector = (object *)victim->query_temp("who_protect");
       if( sizeof(protector) < 1 ) {
       if( victim->query_temp("block_command")) { 
       victim->set_temp("shaked",1);
//       victim->die();
       victim->receive_damage( 180 - kar*random(4)); 
       return 0; }
       else { 
       victim->set_temp("shaked",1);
       return 0;
       }
       }
       for( i=sizeof(protector)-1; i>=0; i-- ) {
       if ( !present(protector[i],environment(me)) ) continue ;
       me->kill_ob(protector[i]);
       }
       return 0;
 }        
