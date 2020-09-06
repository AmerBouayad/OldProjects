//
//  Watch.swift
//  CarouselEffect
//
//  Created by abo on 09/03/2020.
//  Copyright © 2020 abo. All rights reserved.
//

import UIKit

class Watch
{
    // MARK: - Public API
    var featuredImage: UIImage
    var description = ""
    
    init(featuredImage: UIImage, description: String)
    {
        self.featuredImage = featuredImage
        self.description = description
    }
    
    // MARK: - Private
    // dummy data
    static func fetchWatches() -> [Watch]
    {
        return [
            Watch(featuredImage: UIImage(named: "watch-1")!, description: "Watch 1"),
            Watch(featuredImage: UIImage(named: "watch-2")!, description: "Watch 2"),
            Watch(featuredImage: UIImage(named: "watch-3")!, description: "Watch 3"),
        ]
    }
}
