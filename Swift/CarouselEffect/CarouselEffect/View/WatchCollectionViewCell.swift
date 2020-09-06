//
//  WatchCollectionViewCell.swift
//  CarouselEffect
//
//  Created by abo on 09/03/2020.
//  Copyright © 2020 abo. All rights reserved.
//

import UIKit

class WatchCollectionViewCell: UICollectionViewCell {
    
    @IBOutlet weak var featuredImageView: UIImageView!
    @IBOutlet weak var watchDescriptionLabel: UILabel!
    
    var watch: Watch? {
        didSet {
            self.updateUI()
        }
    }
    
    private func updateUI()
    {
        if let watch = watch {
            featuredImageView.image = watch.featuredImage
            watchDescriptionLabel.text = watch.description
        } else {
            featuredImageView.image = nil
            watchDescriptionLabel.text = nil
        }
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
    }
    
}

