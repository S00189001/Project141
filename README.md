## Introduction

## Progress

### Week Seven
This week using the ability system we previously set-up, we have created a new attribute set that each player will be given as default such as:

  - Physical Attack
  - Physical Defence
  - Magic Attack
  - Magic Defence
  - Health
  - Stamina
  - Mana
  - Oxygen
  - Various Resistance Attributes

As well as attributes, we had created the first default player abiltiy which was a simple melee attack. Using these attributes as well as the melee ability, we where able to deal damage from one player to another accross the network based on our attributes.

(_MeleeAttack_)
![image](UE_MultiplayerTemplate/GHPages_Images/MeleeAttack1.png)

Given that we will have various events happen based on time, we decided we would add a day / night cycle. In this day / night cycle we made sure that the sun skybox moved along  with the direction light.

(_Day/Night Cycle_)
![image](UE_MultiplayerTemplate/GHPages_Images/DayNightCycle2.png)

We looked into several different methods to impliment swimming, we choose to use the 3rd person character swimming enum. To allow the user to swim when they enter the water and float when they stop in water.

(_Swimming1_)
![image](UE_MultiplayerTemplate/GHPages_Images/Swimming1.png)

(_Swimming2_)
![image](UE_MultiplayerTemplate/GHPages_Images/Swimming2.png)

(_Swimming3_)
![image](UE_MultiplayerTemplate/GHPages_Images/Swimming3.png)

LOD optomization
Chunk size reduced from 64 to 32

### Week Six
This week we decided to work on setting up the foundations for an ability system. Having spent time researching vaious ability systems, we found unreals GAS (Gameplay Ability System) and decided that we would use this in our project. Most of the week was learning how to use this system and setting up the foundations for abbilities and attributes sets to be created.

### Week Five
Bank holiweek :)
(Busy with personal events)

### Week Four
This week we have been studying on how to use the voxel foliage spawn system on different heights of a IQ noise map. After alot of trail and error we finally managed to get a basic terrain immplemented witch had different height spawners depending on the how high the land was above sea level. We then adjusted the spawners and turned off shadows for grass, flowers and small rocks to improve performance. 

(_World Height Map_)
![image](UE_MultiplayerTemplate/GHPages_Images/Landscape1.png)
This height map was created using an IQ noise and we then applied textures to it depending on how high each area was from sea level.

(_Forest_)
![image](UE_MultiplayerTemplate/GHPages_Images/Landscape2.png)
Picture of the forest area with all foliage spawning as intended.

(_Volumetric Fog_)
![image](UE_MultiplayerTemplate/GHPages_Images/Landscape3.png)
Showcasing a light blue/aquamarine tint to volumetric fog in our forest and near shore height.

(_Shore_)
![image](UE_MultiplayerTemplate/GHPages_Images/Landscape4.png)
Picture of the shore area near the forest

(_Cave_)
![image](UE_MultiplayerTemplate/GHPages_Images/Landscape5.png)
Picture of a hand sculpted cave using the voxel terrain manipulator tools and unreal 4.26 water 

### Week Three

Having completed our research and a lot of planning, we where ready to begin developing our game. Throughout the week, We have created a basic menu system, set-up the foundations and currently have working multiplayer using Steam services. 

(_Main Menu_)
![image](UE_MultiplayerTemplate/GHPages_Images/Menu.PNG)

(_Host Menu_)
![image](UE_MultiplayerTemplate/GHPages_Images/Host.PNG)

(_Server List Menu_)
![image](UE_MultiplayerTemplate/GHPages_Images/ServerLsit.PNG)

(_2 players connected_)
![image](UE_MultiplayerTemplate/GHPages_Images/Connected.PNG)

(_Escape Menu_)
![image](UE_MultiplayerTemplate/GHPages_Images/EscMenu.PNG)

We decided to use the Voxel plugin for unreal as it allows us to randomly generate terrains which would help with speed when designing levels and a possible feature for the player to use to interact / manipulate terrain. 
The free version of the plugin provided us with basic terrain generation and allowed us to shape our worlds but it was missing the ability to spawn meshes so we could not paint our foliage. We then decided to use the pro version which came with this feature and allowed us to edit the terrain and control it using graphs.

(_Terrain Manipulation And generation Using Voxels_)
![image](UE_MultiplayerTemplate/GHPages_Images/Voxel.png)

(_Cave System Using Voxels_)
![image](UE_MultiplayerTemplate/GHPages_Images/Cave.png)

As we are a small team of two and would have multiple roles to cover such as creating our own assets, we decided to learn a new software which we would be using called Blender. This would give us a lot more control over how the game will look as well as keeping the games art style consistant, this didn't prove to time consuming as all members of the team have experience with asset creation.

(_Modelling Practice Using New Software (Blender)_)
![image](UE_MultiplayerTemplate/GHPages_Images/ModellingPractice.png)

### Week Two

Our first couple of weeks where dedicated to research and planning for our project so that it we would get a better understanding of how we will accomplish certain tasks as well as to create a base guidline to stick to throughout the projects development. 

Having spent a lot of time researching various game genres and mechanics before we decided that we would develop an online multiplayer, fantasy, survival game which would be inspired from games such as Rust, Ark and 7DTD with our target release platform being Steam. Although the idea will be heavely inspired from these games, we had designed a unique skill and ability system which will make ours stand out.

### Week One

For our first week of the project, we had mostly been brainstorming ideas for the type of game we want to develop.
