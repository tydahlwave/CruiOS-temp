//
//  MinistryTeam.swift
//  Cru
//
//  Created by Deniz Tumer on 3/2/16.
//  Copyright © 2016 Jamaican Hopscotch Mafia. All rights reserved.
//

import UIKit

class MinistryTeam: Comparable, Equatable{
    var id: String
    var parentMinistry: String
    var description: String
    var ministryName: String
    var image: UIImage!
    var imageUrl: String
    var teamImage: UIImage!
    var teamImageUrl: String
    var leaders: [User]
    var parentMinName: String
    
    init?(dict: NSDictionary) {
        //required initialization of variables
        self.id = ""
        self.parentMinistry = ""
        self.ministryName = ""
        self.description = ""
        self.image = UIImage(named: "event1")
        self.imageUrl = ""
        self.teamImage = UIImage(named: "event1")
        self.teamImageUrl = ""
        self.leaders = [User]()
        self.parentMinName = ""
        
        //grabbing dictionary values
        let dId = dict.object(forKey: "_id")
        let dParentMinistry = dict.object(forKey: "parentMinistry")
        let dDescription = dict.object(forKey: "description")
        let dMinistryName = dict.object(forKey: "name")
        let dImage = dict.object(forKey: "leadersImage")
        let dLeaders = dict.object(forKey: "leaders")
        
        //set up object
        if (dId != nil) {
            self.id = dId as! String
        }
        if (dParentMinistry != nil) {
            self.parentMinistry = dParentMinistry as! String
        }
        if (dDescription != nil) {
            self.description = dDescription as! String
        }
        if (dMinistryName != nil) {
            self.ministryName = dMinistryName as! String
        }
        if (dImage != nil) {
            if let imageUrl = (dImage as AnyObject).object(forKey: "secure_url") {
                self.imageUrl = imageUrl as! String
            }
            else {
                print("error: no image to display")
            }
        }
        else {
            //if image is nil
            self.image = UIImage(named: "fall-retreat-still")
        }
        if let leaderDicts = dLeaders as? [[String:AnyObject]] {
            self.leaders = leaderDicts.map{
                User(dict: $0 as NSDictionary)
            }
        }
    }
    
    func toDictionary() -> NSDictionary {
        return [
            "id": self.id,
            "name": self.ministryName,
            "description": self.description,
            "leaders": self.leaders,
            "imageUrl": self.imageUrl,
            "teamImageUrl": self.teamImageUrl
        ]
    }
}

/* Function for the Comparable & Equatable protocols */
func  < (lTeam: MinistryTeam, rTeam: MinistryTeam) -> Bool{
    if lTeam.parentMinName < rTeam.parentMinName {
        return true
    }
    else if lTeam.parentMinName > rTeam.parentMinName {
        return false
    }
    else if lTeam.parentMinName == rTeam.parentMinName {
        
        if lTeam.ministryName < rTeam.ministryName {
            return true
        }
        
        else {
            return false
        }
        
    }
    return false
}

func  ==(lTeam: MinistryTeam, rTeam: MinistryTeam) -> Bool{
    return lTeam.id == rTeam.id
}
