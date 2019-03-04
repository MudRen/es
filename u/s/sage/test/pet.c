 // this file is called by every pet files
#include <mudlib.h>
#include <move.h>

#define PETS_HOME "/d/noden/farwind/pet_shop"

inherit MONSTER;

void disappear(object pet)
{
        string pet_type;
        if( !pet ) return;
        tell_room( environment(pet),
                pet->query("c_name")+
                "��Ϊ����������ȥ, ����Ҳ���ĵ��뿪��������硣\n"
                , pet
        );
        pet_type = (string)pet->query("pet_type");
        if( pet_type )
        PETS_HOME->add_amount(pet_type);
    pet->remove();
}

void receive_message(string class, string msg)
{
        string who, dir, master, item;
        object master_player;

        master_player = (object)this_object()->query("pet_master");

// if no master or master dead, then destruct me, wuwu.....
        if( !master_player ) {
        call_out("disappear",2,this_object());
                return;
        }

        if ( present(master_player,environment(this_object())) )
            return;
        if ( !query("stop") )
                this_object()->move_player( environment(master_player), "" );
            return ;
}

int order_me(string arg)
{
        object master_player;
        string dir;

    master_player = (object)this_object()->query("pet_master");
    if( !master_player ) this_object()->remove();
// added by Kyoko, prevent if more than 1 pet here....
    if( this_player() != master_player ) return 0;
// make the order cmd work.
      if( !arg || arg == "quit" || sscanf(arg,"get %s",dir) || sscanf(arg,"kill %s",dir))
                return notify_fail("��ĳ���գ���޹����۾������� !\n");
        if( arg == "stay" ) {
                tell_object( master_player,
                        "��ĳ���������عԹ�����, һ��Ҳ������\n"
                );
                this_object()->set("stop", 1);
        } else if( arg == "follow" ) {
                tell_object( master_player,
                        "��ĳ�����˵����˹���, �������ת��\n"
                );
                this_object()->set("stop", 0);
        } else command(arg);
    return 1;
}

void set_master(object master)
{
        object ob;
        string c_name, name;
        
        if( !master ) return;
        ob = this_object();
        name = (string)ob->query("post_name");
        c_name = (string)ob->query("c_post_name");

        ob->set("no_attack",1);

        ob->set("mountable",0);
        ob->set("pet_master", master);
        ob->set("name", master->query("name")+name);
        ob->add("id",({ (string)ob->query("name") }) );
        ob->set("c_name", master->query("c_name")+c_name);
        ob->set("short", master->query("short")+c_name);
        ob->set("protector", master );
        ob->set("wimpy", 90);
        ob->set("stop", 0);
        ob->set("brief",1);
}

void die()
{
        object killer, master;
        
        killer = (object)this_object()->query("last_attacker");
        master = (object)this_object()->query("pet_master");
        if( killer && master ) {
          tell_object( killer, 
                sprintf("\n%s˵: ���۸���, �ҵ����˻���ұ����!!\n\n",
                        this_object()->query("c_name"))
          );
          tell_object( master, 
                sprintf("\n��ĳ������˵: ����, %s�۸���, ����ұ���! һ��Ŷ!\n\n",
                        killer->query("c_name"))
          );
        }
        master->set_temp("now_pet", 0);
        ::die();
}

int call_help()
{
        object master, killer;
        master = (object)this_object()->query("pet_master");
        killer = (object)this_object()->query_attacker();
        if( !killer || !master || master->query_attacker() || 

                !present(master, environment(this_object())) ) return 0;
        tell_room( environment(this_object()), 
                sprintf("%s�ܹ�ȥ�������ĳ���!!\n",
                        master->query("c_name"))
                  , ({ master, this_object() })
        );
        tell_object( master, 
                "���ܹ�ȥΪ������ĳ����ս!!\n"
        );
        master->kill_ob(killer);
        return 0;
}

/*
int query_moving()
{
//      object master;
//      master = this_object()->query("pet_master");
//      if( !master || !present(master, environment(this_object())) ) return 1;
        return 0;
}
*/
int help_order(string arg)
{
        string tmp;
        if( !arg || sscanf(arg, "order_%s", tmp)!=1 ) return 0;
        write( @HELP
Format: order_<pet_name> <command>
command ��Ϊһ�� user ʹ�õ�ָ��, �����ﲻ�� get �κ������
��������� stay & follow  ��������ĳ���Ҫ��Ҫ�����㡣
HELP
        );
        return 1;
}
