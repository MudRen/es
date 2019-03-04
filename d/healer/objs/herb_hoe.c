#include <mudlib.h>

inherit WEAPON;

void init()
{
	add_action("dig_herb","dig" );
        add_action("help","help" ) ;
}

void create()
{
        seteuid( getuid() ) ;
        
	set_name("Herb Hoe","ҩ��");
	add( "id" , ({ "hoe" }) );
	set_short("a set of herb how." , "ҩ��");
	set_long("һ����ҽ�߲�ҩ�õ�ҩ����\n");
   	set("unit","��");
   	set("weight", 15);
	set( "type","blunt");
	set( "second",1);
	set( "min_damage",5);
	set( "max_damage",12);
	set( "weapon_class",12);
   	set("value", ({200, "silver"}) );
}

int what_tree(object ob,string str)
{
    string c_name,name;
    c_name=(string)ob->query("c_realname");
    name=(string)ob->query("realname");

    if(c_name==str || name==str)
      { ob->set("test",1) ;
        return 1 ;
       }
    return 0 ;   
}

int dig_herb(string arg)
{       
        int num ;
        string s1,s3 ; 
        object *the_tree,new_herb,plant,dest ;
        int purified;
        int ok;
        string *verified;
        string s, temp;
        int i;
            
	if( !arg ) return 0 ;
	
	if(sscanf(arg,"%s %d %s",s1,num,s3)!=3)
	   { if(sscanf(arg,"%s %d",s1,num)!=2) 
               {  s1 = arg ;       
                  num = 1  ;
                }
            }  
        else       	         
	   {
	    return notify_fail("too much argument") ;
	    }
	             
	
        the_tree = filter_array(all_inventory(environment(this_player())),
                     "what_tree",this_object(),s1) ;

        if(sizeof(the_tree)==0) 
           {
            write(
                "�����������ҵ�ʲ��??\n"
                ) ;
            return 1 ;
            }
        dest  = this_player() ;
        plant = the_tree[num-1] ;
        
        if ( this_player()->query_temp("last_verify") ){
          verified=explode(this_player()->query_temp("last_verify"),"\n");
          ok = 0;
          sscanf(identify(plant),"%s/%s",s,temp);
          for ( i = 0 ; i < sizeof(verified) ; i ++) {
            if ( (verified[i]) == temp )
            ok=1;
          }
        }
        else ok = 0;
   
        if ( ok == 0) { write("ι! û��ʶ���������, �ֳ����������?\n");
                        return 1;
                      }  
        purified= plant->query("purified");
        if (purified>0) plant->set("purified",(purified-1)) ;
        else { write ( "�ܱ�Ǹ, ���ֲ�������õĲ��ݶ��ѱ������ˡ�\n"); 
               return 1;
             }   
        new_herb=new(plant->query("herb_path")+plant->query("herb_file")) ;
        new_herb->move(this_player()) ;

        write( "���"+plant->query("c_realname")+"����һ"+new_herb->query("unit")
               +new_herb->query("c_name")+"����\n"
              ) ;
               
	tell_room( environment(this_player()), 
		dest->query("c_name")+"��"+plant->query("c_name")+
		"����һ"+new_herb->query("unit")+new_herb->query("c_name")+
		"����\n" 
	  , this_player() );
	if ( purified == 1 ) {
	  write( "\n���ֲ�����㲻�ϵĴ߲�֮��, ��춿�ή�����ˡ�\n" );
	  tell_room( environment(this_player()) ,
	             "\n"+ 
	             plant->query("c_name")+"��"+dest->query("c_name")  
                     +"���Ĳ�֮��, ��춿�ή�����ˡ�\n",
                     this_player() );
          plant->remove();
          if (plant) destruct(plant);
        }             	
	return 1;
}

int help(string arg)
{
     if(!arg || (arg !="hoe"&&arg!="herb hoe")) 
        return 0 ;

     write( can_read_chinese(this_player())? 
  " ҩ����ÿ���о��飬��������ҩ����ҽ�����ر��Ĺ��ߡ�\n"
  " ������Ϊ�ܶ�ҩ���෴��ҩ�ݳ��ü�Ϊ���ƣ���ʱ������\n"
  " Ҷ������Ĳ����ѡ�Ϊ�Ɐ�緢��������һ��Ҫ����\n"
  " ��ʶ<verify>��ֲ����ܼ��Բɼ���\n\n"
  "  �ɼ��ķ���Ϊ   dig <ֲ��ѧ��>\n"
   : ""    
    );
    return 1 ;
}
